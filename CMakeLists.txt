cmake_minimum_required(VERSION 3.25)
project(SDLWrap2)

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)

add_library(SDLWrap2 STATIC library.cpp)
