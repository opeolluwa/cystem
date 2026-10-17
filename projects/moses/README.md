# moses

Interactive CLI that scaffolds a C++20 project — source layout, CMake build,
GoogleTest suite, and a README — from the terminal.

## Description

`moses` walks you through a few prompts and lays down a new C++ project in the
current directory. It asks whether to use CMake, the app name, the CMake
version, whether to add GoogleTest, and whether to add a README, then writes:

- `src/main.cpp`
- `src/<app_name>.hpp` and `src/<app_name>.cpp`
- `CMakeLists.txt` (optional), with GoogleTest wired through `FetchContent`
- `tests/<app_name>_spec.cpp` (optional)
- `README.md` (optional)

Existing files are never overwritten silently — you are asked before each write.

## Getting Started

### Dependencies

* A C++20 compiler (GCC 13+, Clang 16+, or Apple Clang 15+)
* CMake 4.4.2+
* `termcolor` and GoogleTest, fetched automatically by CMake via `FetchContent`

### Installing

```sh
git clone https://github.com/opeolluwa/cystem
cd cystem/projects/moses
cmake -S . -B build
cmake --build build
```

### Executing program

Run the generator inside an empty directory:

```sh
mkdir myapp && cd myapp
/path/to/build/moses
```

You will be prompted for:

```
Use CMake? y/n:
App name:
Cmake version:
add gtest y/n:
add readme? y/n:
```

## Help

* Boolean prompts accept only `y`/`n`; anything else fails with
  `invalid format, expected y/n`.
* When a target file already exists you are asked `... exists, overwrite?` —
  answer `n` to keep the existing file.
* The CMake version you type is written verbatim into
  `cmake_minimum_required` (there is a TODO to detect the installed version).

## Authors

Adefemi Adeoye — [@opeolluwa](https://github.com/opeolluwa)

## Version History

* 0.1
    * Initial Release

## License

Part of the [cystem](https://github.com/opeolluwa/cystem) repository; no
standalone license file is present yet.

## Acknowledgments

* [termcolor](https://github.com/ikalnytskyi/termcolor)
* [GoogleTest](https://github.com/google/googletest)
* [PurpleBooth README template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
