//
// Created by nevemlaci on 14/07/2024.
//

#include <iostream>

#include "../src/cppSDL.hpp"

#define SURFACEEXAMPLE

void SurfaceExample(){
    SDL::Init();
    {
        bool should_be_running = true;
        SDL::Window window("Test", 800, 600, SDL_WINDOW_RESIZABLE);
        SDL::Surface surface("../test/test.bmp");
        SDL::Surface bg("../test/back.bmp");
        std::cout << SDL_GetError();
        SDL::Event event;
        bool windowresized = false;
        while (true) {
            windowresized = false;
            while(event.Poll()) {
                switch (event.GetType()) {
                    case SDL_QUIT:
                        should_be_running = false;
                        break;
                    case SDL_WINDOWEVENT_RESIZED:
                        windowresized = true;
                        break;
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                        windowresized = true;
                    default:
                        break;
                }
                if(!should_be_running) break;
            }

            if(!should_be_running) break;


            if(windowresized) {
                window.UpdateSurface();
            }



            window.GetSurface().CopyIn(bg,
                SDL::Rect{0, 0, bg.GetSize().w, bg.GetSize().h},
                SDL::Rect{0, 0, window.GetSize().w, window.GetSize().h});

            window.GetSurface().CopyIn(surface,
                SDL::Rect{0, 0, 50, 50},
                SDL::Rect{10, 10, 50, 50});

            window.UpdateSurface();

        }
    }

    SDL_Quit();
}

int main(int argc, char** argv){
#ifdef SURFACEEXAMPLE
    SurfaceExample();
#endif
    return 0;
}