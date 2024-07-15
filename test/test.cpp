//
// Created by nevemlaci on 14/07/2024.
//


#include <iostream>

#include "../src/cppSDL.hpp"

int main(int argc, char** argv){
    if(SDL::Init()) {
        std::cout << "Succesful init.";
    }
    SDL::Window window("Test", 800, 600, 0);
    SDL::Event event;
    while (true) {
        while(event.Poll()) {
            switch (event.GetType()) {
                case SDL_QUIT:
                    SDL::Quit();
                    return 0;
                default:
                    break;
            }
        }
    }


    SDL::Quit();
    return 0;
}