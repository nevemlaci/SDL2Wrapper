//
// Created by nevemlaci on 14/07/2024.
//


#include <iostream>

#include "../src/cppSDL.hpp"

int main(int argc, char** argv){
    SDL::Init();
    {
        bool should_be_running = true;
        SDL::Window window("Test", 800, 600, 0);
        SDL::Event event;
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
        }
    }

    SDL_Quit();
    return 0;
}