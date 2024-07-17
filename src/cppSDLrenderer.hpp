//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <cstdint>
#include "cppSDLConcepts.hpp"
#include "cppSDLtexture.hpp"


namespace SDL{
    using RenderFlags = std::uint32_t;

    using FlipMode = SDL_RendererFlip;
    class RWindow;
    class Renderer{
        SDL_Renderer* m_renderer;
    public:
        explicit Renderer(const RWindow& window, RenderFlags flags = 0);
        Renderer(const RWindow& window, int driver, RenderFlags flags = 0);
        ~Renderer();

        SDL_Renderer* GetSDLRenderer() const {
            return m_renderer;
        }

        void RenderClear();

        void RenderPresent();

        void RenderCopy(
            IRenderable& rendered_context, std::optional<Rect> srcrect = {}, std::optional<Rect> dstrect = {},
            double angle = 0, std::optional<Point> center = {},
            FlipMode flip_mode = FlipMode::SDL_FLIP_NONE);

        /*
        void RenderCopy(
            IRenderable& rendered_context, std::optional<Rect> srcrect, std::optional<FRect> dstrect,
            double angle = 0, FPoint center = FPoint{dstrect.value().w/2, dstrect.value().h/2},
            FlipMode flip_mode = FlipMode::SDL_FLIP_NONE);
        */
    };
}
