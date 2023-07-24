#pragma once

namespace just_dl {
    // Various flags
    // Those beginning with `Linux` are Linux specific, `Windows` - Windows specific
    // Flags that do not begin with `Linux` or `Windows` work on both platforms
    // Flags passed to the incorrect platform are just ignored
    enum Flags : unsigned int {
        // Resolve functions only as needed, not at load time
        LinuxLazyLoading = 1 << 0
    };
}
