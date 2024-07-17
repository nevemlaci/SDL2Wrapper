//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLtexture.hpp"

#include <cassert>

#include "cppSDLrenderer.hpp"
#include <SDL_image.h>

SDL::Texture::Texture(const Surface& surface, Renderer& renderer) :
    IRenderable(SDL_CreateTextureFromSurface(renderer.GetSDLRenderer(), surface.GetSDLSurface())), m_renderer(renderer) {}
SDL::Texture::Texture(const std::string& path, Renderer& renderer) :
    IRenderable(IMG_LoadTexture(renderer.GetSDLRenderer(),path.c_str())), m_renderer(renderer)
{}

SDL::Texture::Texture(const Texture& other) : IRenderable(nullptr), m_renderer(other.m_renderer) {
    assert(m_renderer.CanRenderToTextures() && "This renderer cannot render to other textures.");

    Uint32 format;
    int w, h;
    SDL_BlendMode blend_mode;
    SDL_Texture* rendertarget;
    SDL_Texture* new_texture;

    SDL_QueryTexture(other.m_texture, &format, nullptr, &w, &h);
    SDL_GetTextureBlendMode(other.m_texture, &blend_mode);
    rendertarget = SDL_GetRenderTarget(m_renderer.GetSDLRenderer());
    new_texture = SDL_CreateTexture(m_renderer.GetSDLRenderer(), format, SDL_TEXTUREACCESS_TARGET, w, h);
    SDL_SetTextureBlendMode(new_texture, SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(m_renderer.GetSDLRenderer(), new_texture);
    SDL_RenderCopy(m_renderer.GetSDLRenderer(), other.m_texture, nullptr, nullptr);
    SDL_SetTextureBlendMode(new_texture, blend_mode);
    SDL_SetRenderTarget(m_renderer.GetSDLRenderer(), rendertarget);

    m_texture = new_texture;
}

