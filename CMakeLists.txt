cmake_minimum_required(VERSION 3.20)

option(JUSTDL_BUILD_TESTS "Build tests alongside the library" OFF)
option(BUILD_SHARED_LIBS "Build the library as static or dynamic" OFF)

project("just-dl" LANGUAGES CXX)

add_subdirectory(just-dl)

if(CPPBLOWFISH_BUILD_TESTS)
    add_subdirectory(tests)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "just_dl: Building shared library: ${BUILD_SHARED_LIBS}")
message(STATUS "just_dl: Building tests: ${CPPBLOWFISH_BUILD_TESTS}")
