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
    class Window;
    class Renderer{
        SDL_Renderer* m_renderer;
    public:
        explicit Renderer(const Window& window, RenderFlags flags = 0);
        Renderer(const Window& window, int driver, RenderFlags flags = 0);
        ~Renderer();

        SDL_Renderer* GetSDLRenderer() const {
            return m_renderer;
        }

        void RenderCopy(IRenderable& rendered_context, std::optional<Rect> srcrect, std::optional<Rect> dstrect, double angle, Point center, FlipMode flip_mode);

        void RenderCopy(IRenderable& rendered_context, std::optional<Rect> srcrect, std::optional<FRect> dstrect, double angle, FPoint center, FlipMode flip_mode);

    };
}
