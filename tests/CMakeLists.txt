cmake_minimum_required(VERSION 3.20)

function(set_cpp_standard target)
    target_compile_features(${target} PRIVATE cxx_std_17)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
endfunction()

if(UNIX)
    add_subdirectory(linux)
elseif(MSVC)
    add_subdirectory(windows)
else()
    message(FATAL_ERROR "Platform not supported (for now at least)")
endif()
