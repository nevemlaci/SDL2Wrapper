//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <cstdint>
#include "cppSDLwindowsurface.hpp"
#include "interface/iwindow.hpp"

namespace SDL{

    struct WindowSizeData;
    struct WindowPositionData;
    class SWindow : public IWindow{
    private:
        SDL::WindowSurface m_surface;
    public:
        /**
         * @brief Create a window with the specified dimensions at the center of the screen, with the specified flags.
         * @param title the title of the window
         * @param w 	the width of the window, in screen coordinates
         * @param h     the height of the window, in screen coordinates
         * @param flags 0, or one or more WindowFlags (bitwise)OR'd together.
         */
        SWindow(const std::string& title, int w, int h, WindowFlags flags = 0);
        /**
         * @brief Create a window with the specified dimensions at the center of the screen, with the specified flags.
         * @param title the title of the window
         * @param x 	the x position of the window
         * @param y     the y position of the window
         * @param w 	the width of the window, in screen coordinates
         * @param h     the height of the window, in screen coordinates
         * @param flags 0, or one or more WindowFlags (bitwise)OR'd together.
         */
        SWindow(const std::string& title, int x, int y, int w, int h, WindowFlags flags = 0);
        ~SWindow();

        void UpdateSurface();

        SDL::WindowSurface& GetSurface();

    };


}
