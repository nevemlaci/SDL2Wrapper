cmake_minimum_required(VERSION 3.25)
project(cppSDL)

set(CMAKE_CXX_STANDARD 26)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -fdiagnostics-color=always")
endif ()


if(NOT DEFINED ADDEXE)
    set(ADDEXE OFF)
endif (NOT DEFINED ADDEXE)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_definitions(-DSDL_MAIN_HANDLED)

add_library(${PROJECT_NAME} STATIC
        src/cppSDL.cpp
        src/cppSDL.hpp
        src/cppSDLexception.hpp
        src/cppSDLevent.cpp
        src/cppSDLevent.hpp
        src/cppSDLwindow.cpp
        src/cppSDLwindow.hpp
        src/cppSDLsurface.cpp
        src/cppSDLsurface.hpp
        src/cppSDLrect.hpp
        src/interface/isurface.hpp
        src/interface/isurface.cpp
        src/cppSDLwindowsurface.cpp
        src/cppSDLwindowsurface.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 PRIVATE SDL2_image::SDL2_image PRIVATE SDL2_ttf::SDL2_ttf PRIVATE SDL2_mixer::SDL2_mixer)

if(ADDEXE)
    add_executable(Test test/test.cpp)

    target_link_libraries(Test PRIVATE ${PROJECT_NAME} PRIVATE SDL2::SDL2 PRIVATE SDL2_image::SDL2_image PRIVATE SDL2_ttf::SDL2_ttf PRIVATE SDL2_mixer::SDL2_mixer)
endif (ADDEXE)
