#include <string_view>

#include "just_dl/just_dl.hpp"
#include "just_dl/details/interface.hpp"
#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"

#if !defined(__linux__) && !defined(_WIN32)
    #error "Platform not supported (for now at least)"
#endif

namespace just_dl {
    void* open_library(std::string_view library_name, unsigned int flags, Error& err) {
        return platform::open_library(library_name.data(), flags, err);
    }

    void close_library(void* library_handle, Error& err) {
        return platform::close_library(library_handle, err);
    }

    Function load_function(void* library_handle, std::string_view function_name, Error& err) {
        Function function = nullptr;

        platform::load_function(library_handle, function_name.data(), function, err);

        return function;
    }
}
