//
// Created by nevemlaci on 17/07/2024.
//

#pragma once
#include <concepts>
#include <SDL2/SDL.h>

namespace SDL{
    using Rect = SDL_Rect;
    using FRect = SDL_FRect;
    using Point = SDL_Point;
    using FPoint = SDL_FPoint;

    template<typename T>
    concept is_sdl_rect = std::same_as<T, Rect> || std::same_as<T, FRect>;
}
