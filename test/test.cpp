//
// Created by nevemlaci on 14/07/2024.
//

#include <iostream>

#include "../src/cppSDL.hpp"

void SurfaceExample(){
    SDL::Init();
    SDL::IMG::Init();
    {
        bool should_be_running = true;
        SDL::Window window("Software rendering with surfaces and blit - Example", 800, 600, SDL_WINDOW_RESIZABLE);
        SDL::Surface surface("../test/test.bmp");
        SDL::Surface surface2(surface);
        SDL::Surface bg("../test/back.bmp");
        std::cout << SDL_GetError();
        SDL::Event event;
        if(!surface.SaveBMP("../test/test_save_surface.bmp")) SDL_GetError();
        while (true) {
            while(event.Poll()) {
                switch (event.GetType()) {
                    case SDL_QUIT:
                        should_be_running = false;
                        break;
                    default:
                        break;
                }
                if(!should_be_running) break;
            }

            if(!should_be_running) break;

            window.GetSurface().CopyIn(bg,
                SDL::Rect{0, 0, bg.GetSize().w, bg.GetSize().h},
                SDL::Rect{0, 0, window.GetSize().w, window.GetSize().h});

            window.GetSurface().CopyIn(surface,
                SDL::Rect{0, 0, 50, 50},
                SDL::Rect{10, 10, 50, 50});

            /*
            window.GetSurface().CopyIn(surface2,
                SDL::Rect{0, 0, 50, 50},
                SDL::Rect{100, 100, 70, 60});
            */
            window.UpdateSurface();

        }
    }
    SDL::Quit();
}

int main(int argc, char** argv){
    SurfaceExample();
    return 0;
}