//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <optional>
#include <SDL2/SDL.h>
#include <string>
#include "../cppSDLrect.hpp"

namespace SDL{

    struct SurfaceSizeData;

    //Interface for Surface objects. Can be initialized by a primitive SDL_Surface*
    class ISurface{
    protected:
        SDL_Surface* m_surface;
    public:
        ISurface(SDL_Surface* sdl_surface) : m_surface{sdl_surface} {}
        virtual ~ISurface() = default;

        ISurface(const ISurface& other);

        SDL_Surface* GetSDLSurface() const {
            return m_surface;
        }

        SurfaceSizeData GetSize() const;

        /**
         * @brief Save a surface in BMP format.
         * @param path
         * @return true on success, false on failure
         */
        bool SaveBMP(const std::string& path) const;

        bool CopyIn(const SDL::ISurface& source, const std::optional<SDL::Rect>& from_rect = {}, const std::optional<SDL::Rect>& to_rect = {});

    };

    struct SurfaceSizeData{
        int w;
        int h;
    };
}