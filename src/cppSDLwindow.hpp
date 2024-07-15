//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <cstdint>
#include "cppSDLsurface.hpp"

namespace SDL{
    using WindowFlags = std::uint32_t; //Reference: https://wiki.libsdl.org/SDL2/SDL_WindowFlags
    struct WindowSizeData;
    struct WindowPositionData;
    class Window{
    private:
        SDL_Window* m_window;
        mutable SDL::Surface m_surface = SDL::Surface(SDL_GetWindowSurface(m_window));
    public:
        /**
         * @brief Create a window with the specified dimensions at the center of the screen, with the specified flags.
         * @param title the title of the window
         * @param w 	the width of the window, in screen coordinates
         * @param h     the height of the window, in screen coordinates
         * @param flags 0, or one or more WindowFlags (bitwise)OR'd together.
         */
        Window(const std::string& title, int w, int h, WindowFlags flags = 0);
        /**
         * @brief Create a window with the specified dimensions at the center of the screen, with the specified flags.
         * @param title the title of the window
         * @param x 	the x position of the window
         * @param y     the y position of the window
         * @param w 	the width of the window, in screen coordinates
         * @param h     the height of the window, in screen coordinates
         * @param flags 0, or one or more WindowFlags (bitwise)OR'd together.
         */
        Window(const std::string& title, int x, int y, int w, int h, WindowFlags flags = 0);
        ~Window();

        WindowSizeData GetSize() const;

        void SetSize(int w, int h);

        WindowPositionData GetPosition() const;

        void SetPosition(int x, int y);

        SDL_Window* GetSDLWindow() const { return m_window; }

        int GetDisplayOfWindow() const;

        void UpdateSurface() const;

        SDL::Surface& GetSurface(bool update = false) const{
            if(update) {
                UpdateSurface();
            }
            return m_surface;
        }

    };

    struct WindowSizeData final{
        int w;
        int h;
    };

    struct WindowPositionData final{
        int x;
        int y;
    };
}
