//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include "interface/isurface.hpp"

namespace SDL{
    class SWindow;
    //Different to a regular surface in that it's underlying SDL_Surface shouldn't be freed by the destructor
    //because SDL already frees it.
    class WindowSurface : public ISurface{
        friend class SWindow;
        WindowSurface(const SWindow& window);
    public:
        ~WindowSurface() override;
        WindowSurface& operator=(const WindowSurface& other);
    };
}