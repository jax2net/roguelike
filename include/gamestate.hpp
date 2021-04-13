#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../src/dungeons.hpp"

struct Gamestate {
    const char *map;
    void update(const char *map);
};

#endif
