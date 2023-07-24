#ifdef __linux__

#include <dlfcn.h>  // TODO no extern "C"?

#include "just_dl/details/flags.hpp"
#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"
#include "just_dl/details/make_error.hpp"

namespace just_dl {
    namespace platform {
        static void clear_error() {
            dlerror();
        }

        void* open_library(const char* library_name, unsigned int flags, Error& err) {
            clear_error();

            void* handle = nullptr;
            const int mode = flags & LinuxLazyLoading ? RTLD_LAZY : RTLD_NOW;

            handle = dlopen(library_name, mode);

            if (handle == nullptr) {
                err = make_error(dlerror());
                return nullptr;
            }

            return handle;
        }

        void close_library(void* library_handle, Error& err) {
            clear_error();

            if (dlclose(library_handle) != 0) {
                err = make_error(dlerror());
            }
        }

        void load_function(void* library_handle, const char* function_name, Function& function, Error& err) {
            clear_error();

            void* symbol = dlsym(library_handle, function_name);

            char* error = dlerror();

            if (error != nullptr) {
                err = make_error(error);
                return;
            }

            *reinterpret_cast<void**>(&function) = symbol;
        }
    }
}

#endif
