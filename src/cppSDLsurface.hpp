//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include <cstdint>
#include <optional>
#include <string>
#include "cppSDLrect.hpp"
#include "interface/isurface.hpp"

namespace SDL{
    using PixelFormat = SDL_PixelFormatEnum;



    class Surface : public ISurface{
    public:
        Surface(SDL_Surface* sdl_surface = nullptr);
        Surface(int width, int height, int depth = 32,
                std::uint32_t red_mask = 0, std::uint32_t green_mask = 0, std::uint32_t blue_mask = 0, std::uint32_t alpha_mask = 0);
        Surface(int width, int height, int depth = 32, PixelFormat format = PixelFormat::SDL_PIXELFORMAT_RGBA32);
        explicit Surface(const std::string& path);

        Surface(const Surface& other);

        ~Surface() override;

        /**
         * @brief Load an image. Overrides the content of the surface
         * @param path_to_bmp
         * @return true on success, false on failure
         */
        bool Load(const std::string& path_to_bmp);
    };


}