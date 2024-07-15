//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <cstdint>

namespace SDL{
    using RenderFlags = std::uint32_t;
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
    };
}
