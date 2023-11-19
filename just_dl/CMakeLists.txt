cmake_minimum_required(VERSION 3.20)

add_library(just_dl
    "include/just_dl/details/error.hpp"
    "include/just_dl/details/flags.hpp"
    "include/just_dl/details/function.hpp"
    "include/just_dl/details/interface.hpp"
    "include/just_dl/details/version.hpp"
    "include/just_dl/just_dl.hpp"

    "src/details/error.cpp"
    "src/platform/linux_dl.cpp"
    "src/platform/windows_dl.cpp"
    "src/just_dl.cpp"
)

if(UNIX)
    target_compile_options(just_dl PRIVATE "-Wall" "-Wextra" "-Wpedantic")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(just_dl PRIVATE "/W3")
else()
    message(WARNING "Compiler is not MSVC or platform is not supported; warnings are not enabled")
endif()

target_include_directories(just_dl PUBLIC "include")
