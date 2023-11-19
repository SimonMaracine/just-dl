#pragma once

#include <string>

namespace just_dl {
    // Error container
    // Every function that can fail, takes and Error object by reference
    // You should check the error like this: `if (err) { ... }`
    class Error {
    public:
        Error() = default;
        Error(const std::string& message);

        ~Error() = default;

        Error(const Error&) = default;
        Error& operator=(const Error&) = default;
        Error(Error&&) = default;
        Error& operator=(Error&&) = default;

        const std::string& message() const;
        operator bool() const;

        void clear();
    private:
        std::string msg;
    };
}
