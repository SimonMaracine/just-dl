#ifdef _WIN32

#include <windows.h>  // TODO no extern "C"?

#include "just_dl/internal/interface.hpp"

namespace just_dl {
    namespace internal {
        void* open_library(const char* name, unsigned int flags) {

        }

        int close_library(void* library_handle) {

        }

        int load_symbol(const char* name) {

        }
    }
}

#endif
