//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLsurface.hpp"

#include "cppSDLexception.hpp"

SDL::Surface::Surface(SDL_Surface* sdl_surface) : m_surface{sdl_surface} {

}

SDL::Surface::Surface(int width, int height, int depth, std::uint32_t red_mask, std::uint32_t green_mask,
    std::uint32_t blue_mask, std::uint32_t alpha_mask) :
    m_surface(SDL_CreateRGBSurface(0, width, height, depth, red_mask, green_mask, blue_mask, alpha_mask)) {}

SDL::Surface::Surface(int width, int height, int depth, PixelFormat format) :
    m_surface(SDL_CreateRGBSurfaceWithFormat(0, width, height, depth, format)){}
SDL::Surface::Surface(const std::string& path_to_bmp) : m_surface(SDL_LoadBMP(path_to_bmp.c_str())) {
    if(!m_surface) {
        throw Exception(SDL_GetError());
    }
}
SDL::Surface::Surface(const Surface& other) : m_surface(nullptr) {
    SDL_BlitSurface(m_surface, nullptr, other.m_surface, nullptr);
}

SDL::Surface::~Surface() {
    SDL_FreeSurface(m_surface);
}

bool SDL::Surface::LoadBMP(const std::string& path_to_bmp) {
    SDL_FreeSurface(m_surface);
    m_surface = SDL_LoadBMP(path_to_bmp.c_str());
    return static_cast<bool>(m_surface);
}
bool SDL::Surface::SaveBMP(const std::string& path) const {
    return SDL_SaveBMP(m_surface, path.c_str()) == 0;
}

bool SDL::Surface::CopyIn(const SDL::Surface& source, const std::optional<SDL::Rect>& from_rect, const std::optional<SDL::Rect>& to_rect) {
    int e;
    if(!from_rect || !to_rect) {
        e = SDL_BlitSurface(source.m_surface, from_rect ? &from_rect.value() : nullptr, m_surface, to_rect ? const_cast<Rect*>(&to_rect.value()) : nullptr );
    }else if(SDL::RectUtil::EqualSize(from_rect.value(), to_rect.value())) {
        e = SDL_BlitSurface(source.m_surface, &from_rect.value(), m_surface, const_cast<Rect*>(&to_rect.value()));
    }else {
        e = SDL_BlitScaled(source.m_surface, &from_rect.value(), m_surface, const_cast<Rect*>(&to_rect.value()));
    }
    return e == 0;
}

SDL::Surface& SDL::Surface::operator=(const Surface& other) {
    if(this == &other) {
        return *this;
    }
    SDL_FreeSurface(m_surface);
    CopyIn(other.m_surface);
    return *this;
}
