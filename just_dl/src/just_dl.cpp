#include "just_dl/just_dl.hpp"

#include "just_dl/details/interface.hpp"

#if !defined(__linux__) && !defined(_WIN32)
    #error "Platform not supported (for now at least)"
#endif

namespace just_dl {
    void* open_library(const std::string& library_name, unsigned int flags, Error& err) {
        return platform::open_library(library_name.c_str(), flags, err);
    }

    void close_library(void* library_handle, Error& err) {
        platform::close_library(library_handle, err);
    }

    Function load_function(void* library_handle, const std::string& function_name, Error& err) {
        Function function {nullptr};

        platform::load_function(library_handle, function_name.c_str(), function, err);

        return function;
    }
}
