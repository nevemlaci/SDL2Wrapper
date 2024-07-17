//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include "cppSDLConcepts.hpp"

namespace SDL{
    using Rect = SDL_Rect;
    using FRect = SDL_FRect;
    using Point = SDL_Point;
    using FPoint = SDL_FPoint;

    namespace RectUtil{
        template<typename T> requires is_sdl_rect<T>
        bool EqualSize(T a, T b) {
            return (a.w == b.w && a.h == b.h);
        }

        template<typename T> requires is_sdl_rect<T>
        bool HasIntersection(const T& a, const T& b);

        template<>
        inline bool HasIntersection<Rect>(const Rect& a, const Rect& b) {
            return SDL_HasIntersection(&a, &b);
        }

        template<>
        inline bool HasIntersection<FRect>(const FRect& a, const FRect& b) {
            return SDL_HasIntersectionF(&a, &b);
        }

        template<typename T> requires is_sdl_rect<T>
        inline bool operator==(T a, T b) {
            return (a.w == b.w && a.h == b.h && a.x == b.x && a.y == b.y);
        }
    }
}