#include <string>

#include "just_dl/details/make_error.hpp"
#include "just_dl/details/error.hpp"

namespace just_dl {
    Error make_error(const std::string& message) {
        return Error(message);
    }
}
