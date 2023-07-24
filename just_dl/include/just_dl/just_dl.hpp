#pragma once

#include <string_view>

#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"

// Forward include
#include "just_dl/details/flags.hpp"

namespace just_dl {
    void* open_library(std::string_view library_name, unsigned int flags, Error& err);
    void close_library(void* library_handle, Error& err);
    Function load_function(void* library_handle, std::string_view function_name, Error& err);
}
