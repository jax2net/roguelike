#ifndef HELPER_H
#define HELPER_H

#include <fstream>
#include <vector>
#include "constants.hpp"

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b,
                    const uint8_t a = 1);
size_t convert_y(size_t y);

#endif
