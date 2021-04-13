#include "../include/draw.hpp"
#include "../include/gamestate.hpp"
#include "../include/constants.hpp"
#include "dungeons.hpp"

void draw_map(Framebuffer &fb, Gamestate &s) {
    uint32_t background = pack_color(255, 255, 255);
    uint32_t wall = pack_color(90, 43, 18);
    uint32_t portal1 = pack_color(0, 255, 255);
    uint32_t portal2 = pack_color(50, 50, 50);
    uint32_t portal3 = pack_color(0, 23, 87);
    uint32_t portal4 = pack_color(50, 200, 50);

    for (size_t i = 0; i < map_w; i++) {
        for (size_t j = 0; j < map_h; j++) {
            switch (s.map[i+(j*map_w)]) {
            case BACKGROUND:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, background);
                break;
            case WALL:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, wall);
                break;
            case PORTAL1:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, portal1);
                break;
            case PORTAL2:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, portal2);
                break;
            case PORTAL3:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, portal3);
                break;
            case PORTAL4:
                draw_block(fb.buffer, i*block_w, j*block_w, block_w, portal4);
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
