//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLswindow.hpp"

#include <iostream>

SDL::SWindow::SWindow(const std::string& title, int w, int h, WindowFlags flags) :
    IWindow(title, w, h, flags), m_surface(SDL::WindowSurface(*this))
{}
SDL::SWindow::SWindow(const std::string& title, int x, int y, int w, int h, WindowFlags flags) :
    IWindow(title, x, y, w, h, flags), m_surface(SDL::WindowSurface(*this))
{}

SDL::SWindow::~SWindow() {

}

void SDL::SWindow::UpdateSurface() {
    SDL_UpdateWindowSurface(m_window);
    m_surface = SDL::WindowSurface(*this);
}

SDL::WindowSurface& SDL::SWindow::GetSurface() {
    return m_surface;
}

