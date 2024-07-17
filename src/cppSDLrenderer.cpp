//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLrenderer.hpp"

#include "cppSDLexception.hpp"
#include "cppSDLrwindow.hpp"
void SDL::Renderer::test_render_to_textures() {
    SDL_RendererInfo info;
    SDL_GetRendererInfo(m_renderer, &info);
    if(!(info.flags | SDL_RENDERER_TARGETTEXTURE)) {
        can_render_to_textures = false;
    }
    can_render_to_textures =  true;
}

SDL::Renderer::Renderer(const RWindow& window, RenderFlags flags) :
    m_renderer(SDL_CreateRenderer(
        window.GetSDLWindow(),
        -1, flags)) {
    test_render_to_textures();
    if(!m_renderer) {
        throw Exception(SDL_GetError());
    }
}
SDL::Renderer::Renderer(const RWindow& window, int driver, RenderFlags flags) :
    m_renderer(SDL_CreateRenderer(
        window.GetSDLWindow(),
        driver, flags)) {
    if(!m_renderer) {
        throw Exception(SDL_GetError());
    }
    test_render_to_textures();
}

SDL::Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}

void SDL::Renderer::RenderClear() {
    SDL_RenderClear(m_renderer);
}

void SDL::Renderer::RenderPresent() {
    SDL_RenderPresent(m_renderer);
}

void SDL::Renderer::RenderCopy(IRenderable& rendered_context, std::optional<Rect> srcrect, std::optional<Rect> dstrect,
                               double angle, std::optional<Point> center, FlipMode flip_mode) {
    SDL_RenderCopyEx(m_renderer, rendered_context.GetSDLTexture(), srcrect ? &srcrect.value() : nullptr, dstrect ? &dstrect.value() : nullptr, angle, center ? &center.value() : nullptr, flip_mode);
}
