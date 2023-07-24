# just-dl

## Load functions from shared libraries in a cross-platform way, on Linux and Windows

I built this library for myself. It requires `C++17`. I tested it on GCC and MSVC.

Check the header files for documentation and check out `tests/**/main.cpp` for some examples.

To use this library, include it as a submodule:

```sh
git submodule add https://github.com/SimonMaracine/just-dl.git <path/to/submodule/folder>
```

Then write this in CMakeLists.txt:

```cmake
add_subdirectory(<path/to/submodule/folder>)
target_link_libraries(<your_target> PRIVATE just_dl)
```

To build with tests, add this:

```cmake
set(JUST_DL_BUILD_TESTS ON)
```

The CMake script builds the library by default as static. If you want it dynamic:

```cmake
set(BUILD_SHARED_LIBS ON)
```
