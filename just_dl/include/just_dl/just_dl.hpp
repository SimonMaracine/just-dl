#pragma once

// Include this header to gain access to the library API
// Don't include other headers

#include <string_view>

#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"

// Forward includes
#include "just_dl/details/flags.hpp"
#include "just_dl/details/version.hpp"

namespace just_dl {
    // Open the specified library and return a handle to it
    // If the function fails, the handle returned is null and the error is set
    // Flags are most likely platform-specific; see flags.hpp header file
    void* open_library(std::string_view library_name, unsigned int flags, Error& err);

    // Close the library sepcified by the handle
    // This operation can, of course, fail
    void close_library(void* library_handle, Error& err);

    // Retrieve the function pointer of the specified function
    // If the function fails, the pointer returned is null and the error is set
    // To be called, the result MUST be reinterpret_cast'ed to the correct function pointer,
    // otherwise undefined behavior kicks in
    // On Linux, trying to retrieve any symbols other than functions is undefined behavior
    Function load_function(void* library_handle, std::string_view function_name, Error& err);
}
