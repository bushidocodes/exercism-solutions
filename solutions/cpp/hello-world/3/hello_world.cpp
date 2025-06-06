#include "hello_world.h"

namespace hello_world {
    auto hello() -> std::string_view {
        return "Hello, World!";
    }
}