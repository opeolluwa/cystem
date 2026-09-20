#pragma once

#include <cctype>
#include <concepts>
#include <exception>
#include <format>
#include <ios>
#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <termcolor/termcolor.hpp>
#include <type_traits>
#include <vector>

namespace boar {

constexpr auto CMAKE_TEMPLATE = R"(cmake_minimum_required(VERSION {0})
    project({1})

    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_executable(${{PROJECT_NAME}})
    target_sources(${{PROJECT_NAME}} PRIVATE src/main.cpp src/{1}.cpp src/{1}.hpp)
    target_link_libraries(${{PROJECT_NAME}} PRIVATE)

    {2}
)";

constexpr auto GTEST_TEMPLATE = R"(enable_testing()
    add_executable(${{PROJECT_NAME}}_tests)
    target_sources(${{PROJECT_NAME}}_tests PRIVATE tests/{0}_spec.cpp src/{0}.cpp src/{0}.hpp)
    target_include_directories(${{PROJECT_NAME}}_tests PRIVATE ${{CMAKE_CURRENT_SOURCE_DIR}})
    target_link_libraries(${{PROJECT_NAME}}_tests PRIVATE GTest::gtest_main)

    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
    gtest_discover_tests(${{PROJECT_NAME}}_tests)
)";

constexpr auto README_TEMPLATE = R"(# {0}
    
    Simple overview of use/purpose.
    
    ## Description
    
    An in-depth paragraph about your project and overview of use.
    
    ## Getting Started
    
    ### Dependencies
    
    * Describe any prerequisites, libraries, OS version, etc., needed before installing program.
    * ex. Windows 10
    
    ### Installing
    
    * How/where to download your program
    * Any modifications needed to be made to files/folders
    
    ### Executing program
    
    * How to run the program
    * Step-by-step bullets
    ```
    code blocks for commands
    ```
    
    ## Help
    
    Any advise for common problems or issues.
    ```
    command to run if program contains helper info
    ```
    
    ## Authors
    
    Contributors names and contact info
    
    ex. Dominique Pizzie
    ex. [@DomPizzie](https://twitter.com/dompizzie)
    
    ## Version History
    
    * 0.2
        * Various bug fixes and optimizations
        * See [commit change]() or See [release history]()
    * 0.1
        * Initial Release
    
    ## License
    
    This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details
    
    ## Acknowledgments
    
    Inspiration, code snippets, etc.
    * [awesome-readme](https://github.com/matiassingers/awesome-readme)
    * [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
    * [dbader](https://github.com/dbader/readme-template)
    * [zenorocha](https://gist.github.com/zenorocha/4526327)
    * [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
            )";
struct Options {
  std::vector<std::string> dirs;
  std::string app_name;
  bool use_cmake;
  std::optional<std::string> cmake_version;
  bool add_readme;
  bool add_gtest;
};

class Boar {
private:
  Options option;
  std::string build_cmake_template();
  void file_exist_or_create(std::string_view file_name,
                            std::string_view content);

public:
  Boar() = default;
  explicit Boar(const Options &opts);
  Options parse_options();
  void exec();
};

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

}; // namespace boar
