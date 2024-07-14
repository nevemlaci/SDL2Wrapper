//
// Created by nevemlaci on 14/07/2024.
//


#include <iostream>

#include "../src/cppSDL.hpp"

int main(int argc, char** argv){
    if(SDL::Init()) {
        std::cout << "Succesful init.";
    }
    return 0;
}