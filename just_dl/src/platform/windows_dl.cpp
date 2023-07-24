#ifdef _WIN32

#include <string>

#define NO_STRICT
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>  // TODO no extern "C"?

#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"
#include "just_dl/details/make_error.hpp"

namespace just_dl {
    namespace platform {
        static std::string get_error_message(DWORD code) {
            LPTSTR buffer = nullptr;

            const DWORD result = FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                nullptr,
                code,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (LPTSTR) &buffer,
                0,
                nullptr
            );

            if (result == 0) {
                return {};
            }

            std::string message {buffer};

            LocalFree(buffer);

            return message;
        }

        void* open_library(const char* library_name, OpenMode mode, Error& err) {
            HMODULE handle = LoadLibrary(library_name);

            if (handle == nullptr) {
                err = make_error(get_error_message(GetLastError()));
                return nullptr;
            }

            return handle;
        }

        void close_library(void* library_handle, Error& err) {
            if (!FreeLibrary(library_handle)) {
                err = make_error(get_error_message(GetLastError()));
            }
        }

        void load_function(void* library_handle, const char* function_name, Function& function, Error& err) {
            FARPROC symbol = GetProcAddress(library_handle, function_name);

            if (symbol == nullptr) {
                err = make_error(get_error_message(GetLastError()));
                return;
            }

            function = reinterpret_cast<Function>(symbol);
        }
    }
}

#endif
