#include "hello_world.h"

using namespace std::literals;

std::string_view hello_world::hello() {
    return "Hello, World!"sv;
}