//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLsurface.hpp"

#include <cassert>
#include <SDL_image.h>

#include "cppSDLexception.hpp"

SDL::Surface::Surface(SDL_Surface* sdl_surface) : ISurface(sdl_surface) {

}

SDL::Surface::Surface(int width, int height, int depth, std::uint32_t red_mask, std::uint32_t green_mask,
    std::uint32_t blue_mask, std::uint32_t alpha_mask) :
    ISurface(SDL_CreateRGBSurface(0, width, height, depth, red_mask, green_mask, blue_mask, alpha_mask)) {
    if(!m_surface) {
        throw Exception(SDL_GetError());
    }
}

SDL::Surface::Surface(int width, int height, int depth, PixelFormat format) :
    ISurface(SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, format)) {
    if(!m_surface) {
        throw Exception(SDL_GetError());
    }
}
SDL::Surface::Surface(const std::string& path) : ISurface(IMG_Load(path.c_str())) {
    if(!m_surface) {
        throw Exception(SDL_GetError());
    }
}
SDL::Surface::Surface(const Surface& other) : ISurface(SDL_CreateRGBSurfaceWithFormat(
    0, other.GetSDLSurface()->w, other.GetSDLSurface()->h, other.GetSDLSurface()->format->BitsPerPixel, other.GetSDLSurface()->format->format)){
    if(SDL_BlitSurface(other.m_surface, nullptr, m_surface, nullptr)!=0) {
        throw Exception(SDL_GetError());
    }

}

SDL::Surface::~Surface() {
    SDL_FreeSurface(m_surface);
}

bool SDL::Surface::Load(const std::string& path_to_bmp) {
    SDL_FreeSurface(m_surface);
    m_surface = IMG_Load(path_to_bmp.c_str());
    return m_surface != nullptr;
}

