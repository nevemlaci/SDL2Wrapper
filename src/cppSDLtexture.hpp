//
// Created by nevemlaci on 15/07/2024.
//

#pragma once

#include "cppSDLsurface.hpp"
#include "interface/irenderable.hpp"

namespace SDL{
    class Renderer;
    class Texture : public IRenderable{
    public:
        Texture(const Surface& surface, const Renderer& renderer);
        Texture(const std::string& path, const Renderer& renderer);
    };
}