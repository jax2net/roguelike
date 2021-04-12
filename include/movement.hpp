#include "draw.hpp"
#include "player.hpp"

bool collision(Framebuffer &fb, Player &p, Gamestate &s);
void move_up(Framebuffer &fb, Player &p, Gamestate &s);
void move_down(Framebuffer &fb, Player &p, Gamestate &s);
void move_left(Framebuffer &fb, Player &p, Gamestate &s);
void move_right(Framebuffer &fb, Player &p, Gamestate &s);
