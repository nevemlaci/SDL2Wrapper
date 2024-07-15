//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLtexture.hpp"

#include "cppSDLrenderer.hpp"
#include <SDL_image.h>

SDL::Texture::Texture(const Surface& surface, const Renderer& renderer) :
    IRenderable(SDL_CreateTextureFromSurface(renderer.GetSDLRenderer(), surface.GetSDLSurface())) {}
SDL::Texture::Texture(const std::string& path, const Renderer& renderer) :
    IRenderable(IMG_LoadTexture(renderer.GetSDLRenderer(),path.c_str()))
{}
