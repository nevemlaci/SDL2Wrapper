//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLwindowsurface.hpp"

#include "cppSDLswindow.hpp"
SDL::WindowSurface::WindowSurface(const SWindow& window) : ISurface(SDL_GetWindowSurface(window.GetSDLWindow())) {}
SDL::WindowSurface::~WindowSurface() {}

SDL::WindowSurface& SDL::WindowSurface::operator=(const WindowSurface& other) {
    m_surface = other.m_surface; //safe to copy like this because window sufraces have the same lifetime as their window.
    return *this;
}
