#include "moses.h"
#include <array>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

using std::string;
using std::string_view;

namespace fs = std::filesystem;

namespace {
// C++ identifiers can't contain '-' etc. (e.g. dir "my-app" -> namespace
// my_app)
string to_identifier(string_view name) {
  string result;
  result.reserve(name.size() + 1);
  for (char c : name) {
    unsigned char uc = static_cast<unsigned char>(c);
    result += (std::isalnum(uc) || c == '_') ? c : '_';
  }
  if (result.empty() || std::isdigit(static_cast<unsigned char>(result[0])))
    result.insert(result.begin(), '_');
  return result;
}
} // namespace

Moses::Moses(const CliOptions &opts) : option(opts) {}

CliOptions Moses::parse_options() {
  CliOptions options;
  options.use_cmake = parse_input<bool>("Use CMake?");
  options.app_name = parse_input<string>("App name");
  if (options.use_cmake) {
    options.cmake_version = parse_input<string>("Cmake version");
    options.add_gtest = parse_input<bool>("add gtest");
  }
  options.add_readme = parse_input<bool>("add readme?");

  return options;
}

CliOptions Moses::parse_new_options(const std::vector<std::string> &args) {
  CliOptions options;
  options.target_dir = args.at(0);
  options.app_name = fs::path(options.target_dir).filename().string();

  if (options.app_name.empty())
    throw std::runtime_error(
        std::format("invalid directory name '{}'", options.target_dir));

  options.use_cmake = true;
  options.add_readme = true;
  options.add_gtest = false;
  options.cmake_version = detect_cmake_version();
  options.non_interactive = true;

  return options;
}

std::string Moses::detect_cmake_version() {
  std::array<char, 256> buffer{};
  std::string version;
  const std::string fallback = "3.20";

  FILE *pipe = popen("cmake --version 2>/dev/null", "r");
  if (!pipe)
    return fallback;

  constexpr string_view prefix = "cmake version ";

  while (std::fgets(buffer.data(), static_cast<int>(buffer.size()), pipe)) {
    string_view line(buffer.data());
    if (line.starts_with(prefix)) {
      version = string(line.substr(prefix.size()));
      while (!version.empty() &&
             (version.back() == '\n' || version.back() == '\r'))
        version.pop_back();
      break;
    }
  }

  if (pclose(pipe) != 0 || version.empty())
    return fallback;

  return version;
}

void Moses::exec() {
  if (option.non_interactive) {
    base_path = option.target_dir;
    if (fs::exists(base_path)) {
      throw std::runtime_error(
          std::format("directory '{}' already exists", base_path.string()));
    }
  } else {
    base_path = fs::current_path();
  }

  fs::create_directories(base_path / "src");

  // Generate main.cpp
  {
    auto main_content = std::format(MAIN_TEMPLATE, option.app_name);
    file_exist_or_create("src/main.cpp", main_content);
  }

  // Generate app header and source
  {
    auto ns_name = to_identifier(option.app_name);
    auto header_content = std::format(APP_HEADER_TEMPLATE, ns_name);
    auto source_content = std::format(APP_SOURCE_TEMPLATE, option.app_name);
    file_exist_or_create(std::format("src/{}.h", option.app_name),
                         header_content);
    file_exist_or_create(std::format("src/{}.cpp", option.app_name),
                         source_content);
  }

  if (option.use_cmake) {
    file_exist_or_create("CMakeLists.txt", build_cmake_template());
    if (option.add_gtest) {
      fs::create_directories(base_path / "tests");
      auto spec_content = std::format(SPEC_TEMPLATE, option.app_name,
                                      to_identifier(option.app_name));
      file_exist_or_create(std::format("tests/{}_spec.cpp", option.app_name),
                           spec_content);
    }
  }

  if (option.add_readme) {
    file_exist_or_create("README.md",
                         std::format(README_TEMPLATE, option.app_name));
  }

  if (option.non_interactive) {
    file_exist_or_create(".gitignore", GITIGNORE_TEMPLATE);
  }
}

void Moses::file_exist_or_create(std::string_view file_name,
                                 std::string_view content) {
  fs::path filepath = base_path / file_name;
  bool can_write =
      !fs::exists(filepath) ||
      parse_input<bool>(std::format("{} exists, overwrite?", file_name));

  if (can_write) {
    if (filepath.has_parent_path())
      fs::create_directories(filepath.parent_path());
    std::ofstream(filepath) << content;
  }
}

std::string Moses::build_cmake_template() {
  auto cmake_gtest_template_addon =
      std::format(GTEST_TEMPLATE, option.app_name);

  if (!option.add_gtest)
    cmake_gtest_template_addon = "";

  return std::format(CMAKE_TEMPLATE,
                     option.cmake_version.value_or(detect_cmake_version()),
                     option.app_name, cmake_gtest_template_addon);
}

template <typename T> T parse_input(std::string_view prompt) {
  constexpr bool is_boolean = std::same_as<T, bool>;
  std::cout << termcolor::blue << prompt << (is_boolean ? " y/n: " : ": ")
            << termcolor::reset;

  if constexpr (is_boolean) {
    char result;
    std::cin >> result;

    result =
        static_cast<char>(std::tolower(static_cast<unsigned char>(result)));

    if (result != 'y' && result != 'n') {
      throw std::runtime_error(
          std::format("invalid format, expected y/n got {}", result));
    }

    return result == 'y';
  }

  T value;

  if (!(std::cin >> value)) {

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    throw std::runtime_error("invalid format");
  }

  return value;
}

void print_usage() {
  std::cout << "usage:\n"
            << "  moses               interactive scaffolding\n"
            << "  moses new <dir>      scaffold a non-interactively into "
               "<dir> (cmake + readme + gitignore)\n";
}
