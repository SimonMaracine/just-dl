# just-dl

## Load functions from shared libraries in a cross-platform way, on Linux and Windows

I built this library for myself. It requires `C++17`. I tested it on `GCC 13` and `MSVC 19.34`.

If you want to use this library and need a specific flag in either `dlopen`, or `LoadLibrary`,
that is not present in this library, open up an issue and I will try to implement it. If you want
`macOS` support with `Clang`, just try to build the library and tell me if it works. Or if you have
any other suggestions, feel free to open an issue.

Check the header files for documentation and check out `tests/**/main.cpp` for some examples.

To use this library, include it as a submodule:

```text
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

## Example

```c++
#include <iostream>
#include <just_dl/just_dl.hpp>

using Cosine = double(*)(double);

int main() {
    just_dl::Error err;

    void* handle = just_dl::open_library("libm.so.6", 0, err);

    if (err) {
        std::cout << "Could not open math library: " << err.message() << '\n';
        return 1;
    }

    Cosine cosine = reinterpret_cast<Cosine>(
        just_dl::load_function(handle, "cos", err)
    );

    if (err) {
        std::cout << "Could not load function: " << err.message() << '\n';
        return 1;
    }

    std::cout << cosine(0.0) << '\n';

    just_dl::close_library(handle, err);

    if (err) {
        std::cout << "Could not close math library: " << err.message() << '\n';
        return 1;
    }

    return 0;
}
```
