//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>
#include <cstdint>
#include <optional>
#include <string>
#include "cppSDLrect.hpp"

namespace SDL{
    using PixelFormat = SDL_PixelFormatEnum;

    class Surface{
        SDL_Surface* m_surface;
    public:
        Surface(SDL_Surface* sdl_surface = nullptr);
        Surface(int width, int height, int depth = 32,
                std::uint32_t red_mask = 0, std::uint32_t green_mask = 0, std::uint32_t blue_mask = 0, std::uint32_t alpha_mask = 0);
        Surface(int width, int height, int depth = 32, PixelFormat format = PixelFormat::SDL_PIXELFORMAT_RGBA32);
        Surface(const std::string& path_to_bmp);

        Surface(const Surface& other);

        ~Surface();
        /**
         * @brief Load a BMP image. Overrides the content of the surface
         * @param path_to_bmp
         * @return true on success, false on failure
         */
        bool LoadBMP(const std::string& path_to_bmp);

        /**
         * @brief Save a surface in BMP format.
         * @param path
         * @return true on success, false on failure
         */
        bool SaveBMP(const std::string& path) const;

        bool CopyIn(const SDL::Surface& source, const std::optional<SDL::Rect>& from_rect = {}, const std::optional<SDL::Rect>& to_rect = {});

        SDL::Surface& operator=(const Surface& other);
    };
}