#include "SDL2/SDL.h"
#include <iostream>
#include <cstring>
#include "../include/framebuffer.hpp"
#include "../include/draw.hpp"
#include "../include/player.hpp"
#include "../include/movement.hpp"
#include "../include/gamestate.hpp"
#include "dungeons.hpp"

// ya know just testing git stuff mane

int main() {

    Framebuffer frame{WIN_WIDTH, WIN_HEIGHT, std::vector<uint32_t>(WIN_WIDTH*WIN_HEIGHT, 255)};

    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Failed to init SDL" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    if (SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) {
        std::cout << "Failed to create window & renderer" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
    if (texture == NULL) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    /* start map */
    Gamestate state{dungeon1};
    /* player init position */
    Player player{300, 300, 50, 5};
    /* draw initial map */
    draw_map(frame, state);
    /* draw player */
    draw_block(frame.buffer, player.x_pos, player.y_pos, player.size, pack_color(255, 0, 255));

    SDL_Event e;
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);
    bool quit = false;
    SDL_Scancode up = SDL_GetScancodeFromKey(SDLK_w);
    SDL_Scancode down = SDL_GetScancodeFromKey(SDLK_s);
    SDL_Scancode left = SDL_GetScancodeFromKey(SDLK_a);
    SDL_Scancode right = SDL_GetScancodeFromKey(SDLK_d);

    // game loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) { quit = true; }
        }
        if (key_state[up]) {
            move_up(frame, player, state);
        }
        if (key_state[down]) {
            move_down(frame, player, state);
        }
        if (key_state[left]) {
            move_left(frame, player, state);
        }
        if (key_state[right]) {
            move_right(frame, player, state);
        }

        // render the game once (i.e. update frame buffer)
        // reinterpret_cast<void *> ???
        SDL_UpdateTexture(texture, NULL, frame.buffer.data(), WIN_WIDTH*4);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
