#ifdef _WIN32

#define NO_STRICT
#include <windows.h>  // TODO no extern "C"?

#include "just_dl/details/interface.hpp"
#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/error.hpp"
#include "just_dl/details/make_error.hpp"

namespace just_dl {
    namespace platform {
        void* open_library(const char* library_name, OpenMode mode, Error& err) {
            HMODULE handle = LoadLibrary(library_name);

            if (handle == nullptr) {
                err = make_error(std::to_string(GetLastError()));  // TODO
                return nullptr;
            }

            return handle;
        }

        void close_library(void* library_handle, Error& err) {
            if (!FreeLibrary(library_handle)) {
                err = make_error(std::to_string(GetLastError()));  // TODO
            }
        }

        void load_function(void* library_handle, const char* function_name, Function& function, Error& err) {
            FARPROC symbol = GetProcAddress(library_handle, function_name);

            if (symbol == nullptr) {
                err = make_error(std::to_string(GetLastError()));  // TODO
                return;
            }

            function = reinterpret_cast<Function>(symbol);
        }
    }
}

#endif
