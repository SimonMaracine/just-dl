cmake_minimum_required(VERSION 3.20)

if(UNIX)
    add_subdirectory(linux)
elseif(MSVC)
    add_subdirectory(windows)
else()
    message(FATAL_ERROR "Platform not supported")
endif()
