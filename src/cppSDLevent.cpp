//
// Created by nevemlaci on 14/07/2024.
//

#include "cppSDLevent.hpp"
int SDL::Event::Poll() {
    return SDL_PollEvent(&m_event);

}
