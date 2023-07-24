#ifdef __linux__

#include <dlfcn.h>  // TODO no extern "C"?

#include "just_dl/details/open_mode.hpp"
#include "just_dl/details/function.hpp"
#include "just_dl/details/error.hpp"
#include "just_dl/details/make_error.hpp"

namespace just_dl {
    namespace platform {
        void* open_library(const char* library_name, OpenMode mode, Error& err) {
            dlerror();

            void* handle = nullptr;

            switch (mode) {
                case OpenMode::Lazy:
                    handle = dlopen(library_name, RTLD_LAZY);
                    break;
                case OpenMode::Immediate:
                    handle = dlopen(library_name, RTLD_NOW);
                    break;
            }

            if (handle == nullptr) {
                err = make_error(dlerror());
                return nullptr;
            }

            return handle;
        }

        void close_library(void* library_handle, Error& err) {
            dlerror();

            if (dlclose(library_handle) != 0) {
                err = make_error(dlerror());
            }
        }

        void load_function(void* library_handle, const char* function_name, Function& function, Error& err) {
            dlerror();

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
