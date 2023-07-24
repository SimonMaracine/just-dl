#include <iostream>

#include <just_dl/just_dl.hpp>

using Cosine = double(*)(double);

int main() {
    just_dl::Error err;

    void* handle = just_dl::open_library("libm.so.6", 0, err);

    if (err) {
        std::cout << "Could not open math library: " << err.message() << '\n';
        return 1;
    }

    Cosine cosine = reinterpret_cast<Cosine>(just_dl::load_function(handle, "cos", err));

    if (err) {
        std::cout << "Could not load function: " << err.message() << '\n';
        return 1;
    }

    std::cout << cosine(0.0) << '\n';

    just_dl::close_library(handle, err);

    if (err) {
        std::cout << "Could not close math library: " << err.message() << '\n';
        return 1;
    }

    return 0;
}
