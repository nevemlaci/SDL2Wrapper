//
// Created by nevemlaci on 15/07/2024.
//

#pragma once

#include "cppSDLsurface.hpp"
#include "interface/irenderable.hpp"

namespace SDL{
    class Renderer;
    class Texture : public IRenderable{
        Renderer& m_renderer;
    public:
        Texture(const Surface& surface, Renderer& renderer);
        Texture(const std::string& path, Renderer& renderer);
        Texture(const Texture& other);
    };
}