cmake_minimum_required(VERSION 3.25)
project(SDLWrap2)

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_definitions(-DSDL_MAIN_HANDLED)

add_library(SDLWrap2 STATIC
        src/cppSDL.cpp
        src/cppSDL.hpp
        src/cppSDLexception.hpp
        src/cppSDLevent.cpp
        src/cppSDLevent.hpp
        src/cppSDLwindow.cpp
        src/cppSDLwindow.hpp
        src/cppSDLsurface.cpp
        src/cppSDLsurface.hpp
        src/cppSDLrect.hpp)

target_link_libraries(SDLWrap2 PRIVATE SDL2::SDL2 PRIVATE SDL2_image::SDL2_image PRIVATE SDL2_ttf::SDL2_ttf PRIVATE SDL2_mixer::SDL2_mixer)

add_executable(Test test/test.cpp)

target_link_libraries(Test PRIVATE SDLWrap2 PRIVATE SDL2::SDL2 PRIVATE SDL2_image::SDL2_image PRIVATE SDL2_ttf::SDL2_ttf PRIVATE SDL2_mixer::SDL2_mixer)