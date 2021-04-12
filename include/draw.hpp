#ifndef DRAW_H
#define DRAW_H

#include "constants.hpp"
#include "helper.hpp"
#include "framebuffer.hpp"
#include "gamestate.hpp"

void draw_map(Framebuffer &fb, Gamestate &s);
void draw_block(std::vector<uint32_t> &buffer, size_t x, size_t y, size_t length, uint32_t color);

#endif
