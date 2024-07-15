//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLrenderer.hpp"
#include "cppSDLwindow.hpp"
SDL::Renderer::Renderer(const Window& window, RenderFlags flags) :
    m_renderer(SDL_CreateRenderer(
        window.GetSDLWindow(),
        -1, flags)) {}
SDL::Renderer::Renderer(const Window& window, int driver, RenderFlags flags) :
    m_renderer(SDL_CreateRenderer(
        window.GetSDLWindow(),
        driver, flags)) {}

SDL::Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}
