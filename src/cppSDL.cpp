//
// Created by nevemlaci on 14/07/2024.
//


#include "cppSDL.hpp"


bool SDL::Init(uint32_t flags) {
    return SDL_Init(flags) == 0;
}

void SDL::Quit() {
    SDL_Quit();
}



