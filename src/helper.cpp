#include "../include/helper.hpp"

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) {
    return (a<<24) + (b<<16) + (g<<8) + r;
}

size_t convert_y(size_t y) {
    return -y + WIN_HEIGHT;
}
