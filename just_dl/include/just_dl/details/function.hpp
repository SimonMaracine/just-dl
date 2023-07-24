#pragma once

namespace just_dl {
    // Dummy function returned by load_function
    // It must be reinterpreted to the correct function pointer before use
    using Function = int(*)();
}
