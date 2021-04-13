#include "../include/movement.hpp"
// edit from portal collision
bool collision(Framebuffer &fb, Player &p, Gamestate &s, size_t x, size_t y) {

    if (s.map[x+(y*map_w)] != ' ') {
        return true;
    }
    return false;
}

void move_up(Framebuffer &fb, Player &p, Gamestate &s) {
    if (p.y_pos > 0) {
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos, p.y_pos-p.speed, p.size, pack_color(255, 0, 255));
        p.y_pos -= p.speed;
    }
}

void move_down(Framebuffer &fb, Player &p, Gamestate &s) {
    // check if OOB
    if (p.y_pos + p.size < fb.h) {
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos, p.y_pos+p.speed, p.size, pack_color(255, 0, 255));
        p.y_pos += p.speed;
    }
}

void move_left(Framebuffer &fb, Player &p, Gamestate &s) {

    if (p.x_pos > 0) {
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos-p.speed, p.y_pos, p.size, pack_color(255, 0, 255));
        p.x_pos -= p.speed;
    }

}

void move_right(Framebuffer &fb, Player &p, Gamestate &s) {
    if (p.x_pos + p.size < fb.w) {
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos+p.speed, p.y_pos, p.size, pack_color(255, 0, 255));
        p.x_pos += p.speed;
    }

}
