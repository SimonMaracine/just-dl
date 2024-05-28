#include "just_dl/details/error.hpp"

namespace just_dl {
    Error::Error(const std::string& message) {
        if (message.empty()) {
            msg = "Unknown error";
        } else {
            msg = message;
        }
    }

    const std::string& Error::message() const {
        return msg;
    }

    Error::operator bool() const {
        return !msg.empty();
    }

    void Error::clear() {
        msg.clear();
    }
}
