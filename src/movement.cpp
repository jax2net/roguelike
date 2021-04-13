#include "../include/movement.hpp"

void portal_collision(size_t x, size_t y, Gamestate &s) {
    int cx = (int) x / block_w;
    int cy = (int) (y / block_w);
    std::cout << "(" << cx << ", " << cy << ")\n";
    switch (s.map[cx+(cy*map_w)]) {
    case PORTAL1:
        s.map = dungeon1;
        break;
    case PORTAL2:
        s.map = dungeon2;
        break;
    case PORTAL4:
        s.map = dungeon4;
        break;
    case PORTAL3:
        s.map = dungeon3;
        break;
    default:
        break;
    }
}

void move_up(Framebuffer &fb, Player &p, Gamestate &s) {
    if (p.y_pos > 0) {
        portal_collision(p.x_pos, p.y_pos, s);
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos, p.y_pos-p.speed, p.size, pack_color(255, 0, 255));
        p.y_pos -= p.speed;
    }
}

void move_down(Framebuffer &fb, Player &p, Gamestate &s) {
    if (p.y_pos + p.size < fb.h) {
        portal_collision(p.x_pos, p.y_pos, s);
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos, p.y_pos+p.speed, p.size, pack_color(255, 0, 255));
        p.y_pos += p.speed;
    }
}

void move_left(Framebuffer &fb, Player &p, Gamestate &s) {
    if (p.x_pos > 0) {
        portal_collision(p.x_pos, p.y_pos, s);
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos-p.speed, p.y_pos, p.size, pack_color(255, 0, 255));
        p.x_pos -= p.speed;
    }
}

void move_right(Framebuffer &fb, Player &p, Gamestate &s) {
    if (p.x_pos + p.size < fb.w) {
        portal_collision(p.x_pos, p.y_pos, s);
        draw_map(fb, s);
        draw_block(fb.buffer, p.x_pos+p.speed, p.y_pos, p.size, pack_color(255, 0, 255));
        p.x_pos += p.speed;
    }
}
