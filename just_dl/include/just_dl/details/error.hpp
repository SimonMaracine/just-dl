#pragma once

#include <string_view>
#include <string>

namespace just_dl {
    // Error container
    // Every function that can fail, takes and Error object by reference
    // You should check the error like this: `if (err) { ... }`
    class Error {
    public:
        Error() = default;
        ~Error() = default;

        Error(const Error&) = default;
        Error& operator=(const Error&) = default;
        Error(Error&&) = default;
        Error& operator=(Error&&) = default;

        std::string_view message() const;
        operator bool() const;

        void clear();
    private:
        Error(const std::string& message);

        std::string msg;

        friend Error make_error(const std::string& message);
    };
}
