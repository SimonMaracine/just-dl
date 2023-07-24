#include <string_view>
#include <string>

#include "just_dl/details/error.hpp"

namespace just_dl {
    std::string_view Error::message() const {
        return msg;
    }

    Error::operator bool() const {
        return !msg.empty();
    }

    void Error::clear() {
        msg.clear();
    }

    Error::Error(const std::string& message) {
        if (message.empty()) {
            msg = "Unknown error";
        } else {
            msg = message;
        }
    }
}
