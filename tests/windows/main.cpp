#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <just_dl/just_dl.hpp>

using get_system_info = void(WINAPI*)(LPSYSTEM_INFO);

int main() {
    just_dl::Error err;

    void* handle = just_dl::open_library("kernel32.dll", 0, err);

    if (err) {
        std::cout << "Could not open system library: " << err.message() << '\n';
        return 1;
    }

    get_system_info MyGetSystemInfo = reinterpret_cast<get_system_info>(just_dl::load_function(handle, "GetSystemInfo", err));

    if (err) {
        std::cout << "Could not load function: " << err.message() << '\n';
        return 1;
    }

    SYSTEM_INFO si;
    MyGetSystemInfo(&si);
    std::cout << si.dwNumberOfProcessors << '\n';

    just_dl::close_library(handle, err);

    if (err) {
        std::cout << "Could not close system library: " << err.message() << '\n';
        return 1;
    }

    return 0;
}
