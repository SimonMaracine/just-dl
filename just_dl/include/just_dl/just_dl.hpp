#pragma once

#include <string_view>

#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/error.hpp"
#include "just_dl/details/function.hpp"

namespace just_dl {
    void* open_library(std::string_view library_name, OpenMode mode, Error& err);
    void close_library(void* library_handle, Error& err);
    Function load_function(void* library_handle, std::string_view function_name, Error& err);
}
