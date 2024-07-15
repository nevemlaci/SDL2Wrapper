//
// Created by nevemlaci on 15/07/2024.
//

#include "cppSDLwindow.hpp"
SDL::Window::Window(const std::string& title, int w, int h, WindowFlags flags) :
    m_window(SDL_CreateWindow(
    title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w,
        h,
        flags)) {}
SDL::Window::Window(const std::string& title, int x, int y, int w, int h, WindowFlags flags) :
    m_window(SDL_CreateWindow(
    title.c_str(),
        x,
        y,
        w,
        h,
        flags)) {}

SDL::Window::~Window() {
    SDL_DestroyWindow(m_window);
}

SDL::WindowSizeData SDL::Window::GetSize() const {
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return SDL::WindowSizeData{w, h};
}

void SDL::Window::SetSize(int w, int h) {
    SDL_SetWindowSize(m_window, w, h);
}
void SDL::Window::SetPosition(int x, int y) {
    SDL_SetWindowPosition(m_window, x, y);
}

int SDL::Window::GetDisplayOfWindow() const {
    return SDL_GetWindowDisplayIndex(m_window);
}

SDL::WindowPositionData SDL::Window::GetPosition() const {
    int x, y;
    SDL_GetWindowPosition(m_window, &x, &y);
    return SDL::WindowPositionData{x, y};
}

