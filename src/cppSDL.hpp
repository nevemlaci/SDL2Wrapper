//
// Created by nevemlaci on 14/07/2024.
//

#pragma once

#include <SDL2/SDL.h>
#include "cppSDLevent.hpp"
#include "cppSDLswindow.hpp"
#include "cppSDLexception.hpp"
#include "cppSDLrect.hpp"
#include "cppSDLsurface.hpp"
#include <cstdint>
#include <SDL_image.h>
#include "cppSDLrenderer.hpp"
#include "cppSDLtexture.hpp"
#include "cppSDLrwindow.hpp"

namespace SDL{
    static constexpr std::uint32_t INIT_EVERYTHING = SDL_INIT_EVERYTHING;
    bool Init(std::uint32_t flags = SDL::INIT_EVERYTHING);
    namespace IMG{
        bool Init(int flags = IMG_INIT_PNG | IMG_INIT_JPG);
    }
    void Quit();
};

