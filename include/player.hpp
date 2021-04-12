#ifndef PLAYER_H
#define PLAYER_H
#include "helper.hpp"
#include "draw.hpp"

struct Player {
    size_t x_pos, y_pos;
    size_t size;
    size_t speed;
};

#endif
