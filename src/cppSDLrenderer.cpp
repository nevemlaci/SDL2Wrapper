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

void SDL::Renderer::RenderCopy(IRenderable& rendered_context, std::optional<Rect> srcrect, std::optional<Rect> dstrect,
double angle, Point center, FlipMode flip_mode) {
    SDL_RenderCopyEx(m_renderer, rendered_context.GetSDLTexture(), srcrect ? &srcrect.value() : nullptr, dstrect ? &dstrect.value() : nullptr, angle, &center, flip_mode);
}
