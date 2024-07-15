//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>

namespace SDL{
    using Rect = SDL_Rect;
    using FRect = SDL_FRect;

    namespace RectUtil{
        template<typename T> requires std::same_as<Rect, T> || std::same_as<FRect, T>
        bool EqualSize(T a, T b) {
            return (a.w == b.w && a.h == b.h);
        }
    }
}