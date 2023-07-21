#include <iostream>

#include <just_dl/just_dl.hpp>

using Cosine = double(*)(double);

int main() {
    just_dl::Error err;

    void* handle = just_dl::open_library("libm.so.6", just_dl::OpenMode::Immediate, err);

    if (err) {
        std::cout << "Could not open math library\n";
        return 1;
    }

    Cosine cosine;
    JUST_DL_SYMBOL_CAST(cosine, just_dl::load_symbol(handle, "cos", err));

    if (err) {
        std::cout << "Could not load function\n";
        return 1;
    }

    std::cout << cosine(0.0) << '\n';

    just_dl::close_library(handle, err);

    if (err) {
        std::cout << "Could not close math library\n";
        return 1;
    }

    return 0;
}
