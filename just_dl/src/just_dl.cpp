#include <string_view>

#include "just_dl/just_dl.hpp"
#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/interface.hpp"
#include "just_dl/details/error.hpp"

#if !defined(__linux__) && !defined(_WIN32)
    #error "Platform not supported (for now at least)"
#endif

namespace just_dl {
    void* open_library(std::string_view library_name, OpenMode mode, Error& err) {
        return platform::open_library(library_name.data(), mode, err);
    }

    void close_library(void* library_handle, Error& err) {
        return platform::close_library(library_handle, err);
    }

    void* load_symbol(void* library_handle, std::string_view symbol_name, Error& err) {
        return platform::load_symbol(library_handle, symbol_name.data(), err);
    }
}
