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

Build from source:

```sh
git clone https://github.com/opeolluwa/cystem
cd cystem/projects/moses
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

`termcolor` and GoogleTest are fetched by CMake at configure time, so the first
build needs network access.

### Installing natively on Unix

Install the built binary into your `PATH` so it can be run as `moses`:

```sh
# System-wide (needs sudo) -> /usr/local/bin/moses
sudo cmake --install build --prefix /usr/local

# ...or user-local, no sudo needed (~/.local/bin must be on your PATH)
cmake --install build --prefix ~/.local
```

If `~/.local/bin` is not on your `PATH` yet, add it to your shell profile
(`~/.zshrc`, `~/.bashrc`, ...):

```sh
export PATH="$HOME/.local/bin:$PATH"
```

Without the CMake install step you can also copy the binary manually:

```sh
install -m 0755 build/moses /usr/local/bin/moses   # or ~/.local/bin
```

To remove it later:

```sh
sudo rm /usr/local/bin/moses   # or rm ~/.local/bin/moses
```

### Executing program

**Non-interactive (recommended)** — scaffold a new project from anywhere:

```sh
moses new myapp
```

This creates `myapp/`, using the directory name as the project name, and
writes `CMakeLists.txt`, `README.md`, `.gitignore` and `src/` (no prompts).
The CMake version is auto-detected from the installed `cmake` (falling back
to `3.20` if CMake is unavailable). If the directory already exists the
command aborts with an error.

**Interactive** — run the generator inside an empty directory:

```sh
mkdir myapp && cd myapp
moses
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
* In interactive mode the CMake version you type is written verbatim into
  `cmake_minimum_required`; `moses new` detects the installed version
  automatically (`cmake --version`).

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
