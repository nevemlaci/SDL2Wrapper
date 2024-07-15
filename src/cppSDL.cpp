//
// Created by nevemlaci on 14/07/2024.
//


#include "cppSDL.hpp"



bool SDL::Init(std::uint32_t flags) {
    return SDL_Init(flags) == 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

bool SDL::IMG::Init(int flags) {
    return IMG_Init(flags);
}

void SDL::Quit() {
    SDL_Quit();
}



