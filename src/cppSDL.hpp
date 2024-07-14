//
// Created by nevemlaci on 14/07/2024.
//

#pragma once

#include <SDL2/SDL.h>

namespace SDL{
    inline constexpr uint32_t INIT_EVERYTHING = SDL_INIT_EVERYTHING;
    bool Init(uint32_t flags = SDL::INIT_EVERYTHING);
}

