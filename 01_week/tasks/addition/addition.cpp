#include <cstdint>
#include <stdexcept>


int64_t Addition(int a, int b) {
    int64_t c = static_cast<int64_t>(a);
    int64_t d = static_cast<int64_t>(b);
    return c + d;
}