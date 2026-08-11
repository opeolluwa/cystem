#include <commander.h>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <mule.h>
#include <stdexcept>
#include <structopt/app.hpp>
#include <termcolor/termcolor.hpp>

namespace fs = std::filesystem;

struct Options {

  // create a new project in the preset working directory
  struct Init : structopt::sub_command {
    std::optional<std::string> name;
    std::optional<std::string> path = ".";
  };
  Init init;

  // crate a new in the provided directory
  struct Create : structopt::sub_command {
    std::optional<std::string> path = ".";
  };
  Create create;

  // build project
  struct Build : structopt::sub_command {
    std::optional<std::string> path = ".";
  };
  Build build;

  // run file in watch mode
  struct Watch : structopt::sub_command {
    std::optional<std::string> path = ".";
  };
  Watch watch;

  // run build application
  struct Exec : structopt::sub_command {
    std::optional<std::string> path = ".";
  };
  Exec exec;
};

STRUCTOPT(Options::Init, name, path);
STRUCTOPT(Options::Create, path);
STRUCTOPT(Options::Build, path);
STRUCTOPT(Options::Watch, path);
STRUCTOPT(Options::Exec, path);
STRUCTOPT(Options, init, create, build, exec, watch);

int main(int argc, char *argv[argc + 1]) {
  try {
    auto app{
        structopt::app(mule::APP, mule::APP_VERSION, mule::APP_HELP_MESSAGE)};
    auto options{app.parse<Options>(argc, argv)};

    if (options.init.has_value()) {
      try {
        commander::init_command(options.init.name, options.init.path);
      } catch (const std::runtime_error &err) {
        std::cout << termcolor::red << err.what() << std::endl;
      }

    } else if (options.create.has_value()) {
      std::cout << "Creating project in " << options.create.path.value()
                << std::endl;
    } else if (options.build.has_value()) {
      std::cout << "Building project in " << options.build.path.value()
                << std::endl;
    } else if (options.watch.has_value()) {
      std::cout << "Watching project in " << options.watch.path.value()
                << std::endl;
    } else if (options.exec.has_value()) {
      std::cout << "Executing project in " << options.exec.path.value()
                << std::endl;
    } else
      std::cout << app.help() << std::endl;

  } catch (const structopt::exception &err) {
    std::cout << termcolor::red << err.what() << std::endl;
    std::cerr << err.help() << std::endl;

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
