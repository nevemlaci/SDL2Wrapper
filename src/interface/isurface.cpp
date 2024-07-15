//
// Created by nevemlaci on 15/07/2024.
//

#include "isurface.hpp"

SDL::SurfaceSizeData SDL::ISurface::GetSize() const {
    return SDL::SurfaceSizeData{m_surface->w, m_surface->h};
}

bool SDL::ISurface::SaveBMP(const std::string& path) const {
    return SDL_SaveBMP(m_surface, path.c_str()) == 0;
}

bool SDL::ISurface::CopyIn(const SDL::ISurface& source, const std::optional<SDL::Rect>& from_rect, const std::optional<SDL::Rect>& to_rect) {
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

/* @TODO should be in WindowSurface
SDL::ISurface& SDL::ISurface::operator=(const ISurface& other) {
    assert(m_is_window_surface == true && "Use SDL::Surface::CopyIn() for non-window surfaces!");
    if(this == &other) {
        return *this;
    }
    SDL_FreeSurface(m_surface);
    m_surface = other.m_surface;
    return *this;
}
*/