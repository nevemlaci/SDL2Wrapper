//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include "interface/isurface.hpp"

namespace SDL{
    class Window;
    class WindowSurface : public ISurface{
        friend class Window;
        WindowSurface(const Window& window);
    public:
        ~WindowSurface() override;
        WindowSurface& operator=(const WindowSurface& other);
    };
}