//
// Created by nevemlaci on 14/07/2024.
//

#pragma once
#include <SDL2/SDL.h>

namespace SDL{
    class Event final{
        SDL_Event m_event{};
    public:
        Event() = default;
        uint32_t GetType() const {
            return m_event.type;
        }

        const SDL_Event& GetSDLEvent() const {
            return m_event;
        }

        int Poll();
    };
}