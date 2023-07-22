#pragma once

#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/error.hpp"
#include "just_dl/details/function.hpp"

namespace just_dl {
    namespace platform {
        void* open_library(const char* library_name, OpenMode mode, Error& err);
        void close_library(void* library_handle, Error& err);
        void load_function(void* library_handle, const char* function_name, Function& function, Error& err);
    }
}
