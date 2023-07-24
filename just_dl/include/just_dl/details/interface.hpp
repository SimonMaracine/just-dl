#pragma once

#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"

namespace just_dl {
    namespace platform {
        void* open_library(const char* library_name, unsigned int flags, Error& err);
        void close_library(void* library_handle, Error& err);
        void load_function(void* library_handle, const char* function_name, Function& function, Error& err);
    }
}
