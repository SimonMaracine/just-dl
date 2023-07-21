#pragma once

#include <string_view>

#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/error.hpp"

#define JUST_DL_SYMBOL_CAST(function_pointer, symbol) \
    *reinterpret_cast<void**>(&function_pointer) = symbol

namespace just_dl {
    void* open_library(std::string_view library_name, OpenMode mode, Error& err);

    void close_library(void* library_handle, Error& err);

    void* load_symbol(void* library_handle, std::string_view symbol_name, Error& err);
}
