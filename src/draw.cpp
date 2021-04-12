#include "../include/draw.hpp"
#include "../include/gamestate.hpp"
#include "../include/constants.hpp"
#include "dungeons.hpp"

void draw_map(Framebuffer &fb, Gamestate &s) {
    uint32_t white = pack_color(255, 255, 255);
    uint32_t green = pack_color(0, 255, 0);
    uint32_t orange = pack_color(0, 255, 255);
    for (size_t i = 0; i < map_w; i++) {
        for (size_t j = 0; j < map_h; j++) {
            switch (s.map[i+(j*map_w)]) {
            case BACKGROUND:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, white);
                break;
            case WALL:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, green);
                break;
            case PORTAL:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, orange);
                break;
            default:
                break;
            }
        }
    }
}

/*
Draw a square
 */
void draw_block(std::vector<uint32_t> &buffer, size_t x, size_t y, size_t length, uint32_t color) {
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length; j++) {
            size_t cx = x+i;
            size_t cy = j+y;
            buffer[cx+(cy*WIN_WIDTH)] = color;
        }
    }
}
