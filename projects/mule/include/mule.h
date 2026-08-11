
#pragma once
#include <vector>
#include <string>
namespace mule {

const std::string APP = "mule";
const std::string APP_VERSION = "0.1.0";
const std::string APP_HELP_MESSAGE =
    R"(mule - a lightweight C/C++ project development tool

    USAGE:
        mule [OPTIONS] <SUBCOMMAND>

    DESCRIPTION:
        mule is a project development tool for creating, building,
        running, and watching C/C++ applications.

    OPTIONS:
        -h, --help
            Print this help message and exit.

        -v, --version
            Print the mule version and exit.

    SUBCOMMANDS:
        init
            Initialize a new mule project in the current directory.

            USAGE:
                mule init [OPTIONS]

            OPTIONS:
                --name <NAME>
                    Name of the project to initialize.

                --path <PATH>
                    Directory in which to initialize the project.
                    Defaults to the current directory (.).

            EXAMPLES:
                mule init --name myapp
                mule init --name myapp --path ./projects/myapp


        create
            Create a new mule project in the specified directory.

            USAGE:
                mule create [OPTIONS]

            OPTIONS:
                --path <PATH>
                    Directory in which to create the project.
                    Defaults to the current directory (.).

            EXAMPLES:
                mule create
                mule create --path ./projects/myapp


        build
            Build the mule project.

            USAGE:
                mule build [OPTIONS]

            OPTIONS:
                --path <PATH>
                    Path to the project to build.
                    Defaults to the current directory (.).

            EXAMPLES:
                mule build
                mule build --path ./myapp


        exec
            Run the built mule application.

            USAGE:
                mule exec [OPTIONS]

            OPTIONS:
                --path <PATH>
                    Path to the project to execute.
                    Defaults to the current directory (.).

            EXAMPLES:
                mule exec
                mule exec --path ./myapp


        watch
            Watch the project for changes and rebuild or rerun
            the application when files are modified.

            USAGE:
                mule watch [OPTIONS]

            OPTIONS:
                --path <PATH>
                    Path to the project to watch.
                    Defaults to the current directory (.).

            EXAMPLES:
                mule watch
                mule watch --path ./myapp


    EXAMPLES:
        Initialize a project:
            mule init --name myapp

        Create a project:
            mule create --path ./projects/myapp

        Build a project:
            mule build

        Run a project:
            mule exec

        Watch a project for changes:
            mule watch

    VERSION:
        mule 0.1.0

    Use 'mule <SUBCOMMAND> --help' for more information about a command.
    )";

const std::vector<std::string> PROJECT_DIRS{"src", "include", "external", "assets"};
const std::vector<std::string> PROJECT_FILES{"CMakeList.txt", "mule.toml"};

} // namespace mule
