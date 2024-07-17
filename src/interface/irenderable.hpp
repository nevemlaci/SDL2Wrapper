//
// Created by nevemlaci on 15/07/2024.
//

#pragma once
#include <SDL2/SDL.h>

namespace SDL{


    class IRenderable{
    protected:
        SDL_Texture* m_texture = nullptr;
    public:
        IRenderable(SDL_Texture* texture) : m_texture(texture) {}
        SDL_Texture* GetSDLTexture() const { return m_texture; }
        virtual ~IRenderable() = default;

        IRenderable(const IRenderable& other);
    };

}
