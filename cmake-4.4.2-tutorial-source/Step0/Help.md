# Getting started with CMake

- `cmake -B <build dir>` if using the default generator
- `cmake -G <generator> -B <build dir>` if specifying the generator

# Generating executable

After the step above, run `cmake --build <build dir>`
If we're using a multi-configuration generator, we will want to specify the build configuration.
`cmake --build build --config Debug`

