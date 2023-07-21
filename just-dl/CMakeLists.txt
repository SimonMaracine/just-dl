cmake_minimum_required(VERSION 3.20)

add_library(just_dl
    "include/just_dl/just_dl.hpp"
    "include/just_dl/platform/windows_dl.hpp"
    "src/just_dl.cpp"
    "src/platform/windows_dl.cpp"
)

if(UNIX)
    target_compile_options(just_dl PRIVATE "-Wall" "-Wextra" "-Wpedantic")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(just_dl PRIVATE "/W3")
else()
    message(WARNING "Compiler is not MSVC or platform is not supported; warnings were not enabled")
endif()

target_include_directories(just_dl PUBLIC "include")

# if(CMAKE_BUILD_TYPE STREQUAL "Release")
#     target_compile_definitions(just_dl PRIVATE "NDEBUG")
#     message(STATUS "just_dl: Building library in release mode")
# endif()

# target_compile_features(just_dl PRIVATE cxx_std_17)
# set_target_properties(just_dl PROPERTIES CXX_EXTENSIONS OFF)
