#pragma once

#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/error.hpp"

namespace just_dl {
    namespace platform {
        void* open_library(const char* library_name, OpenMode mode, Error& err);
        void close_library(void* library_handle, Error& err);
        void* load_symbol(void* library_handle, const char* symbol_name, Error& err);
    }
}
