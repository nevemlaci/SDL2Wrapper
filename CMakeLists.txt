cmake_minimum_required(VERSION 3.25)

project(cppSDL)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

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

file(GLOB resource_files "test.bmp" "back.bmp")

add_library(${PROJECT_NAME} STATIC
        src/cppSDL.cpp
        src/cppSDL.hpp
        src/cppSDLexception.hpp
        src/cppSDLevent.cpp
        src/cppSDLevent.hpp
        src/cppSDLswindow.cpp
        src/cppSDLswindow.hpp
        src/cppSDLsurface.cpp
        src/cppSDLsurface.hpp
        src/cppSDLrect.hpp
        src/interface/isurface.hpp
        src/interface/isurface.cpp
        src/cppSDLwindowsurface.cpp
        src/cppSDLwindowsurface.hpp
        src/cppSDLrenderer.cpp
        src/cppSDLrenderer.hpp
        src/interface/irenderable.hpp
        src/cppSDLtexture.cpp
        src/cppSDLtexture.hpp
        src/cppSDLConcepts.hpp
        src/interface/iwindow.cpp
        src/interface/iwindow.hpp
        src/cppSDLrwindow.cpp
        src/cppSDLrwindow.hpp
        src/interface/irenderable.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 PRIVATE SDL2_image::SDL2_image PRIVATE SDL2_ttf::SDL2_ttf PRIVATE SDL2_mixer::SDL2_mixer)

if(ADDEXE) #only here for testing should make it a different project entirely
    if(MSVC)
        file(COPY ${resource_files} DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
        message("Copying resource files to: ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
    else()
        file(COPY ${resource_files} DESTINATION ${CMAKE_BINARY_DIR})
        message("Copying resource files to: ${CMAKE_BINARY_DIR}")
    endif ()

    add_executable(${PROJECT_NAME}Test test/test.cpp)

    target_link_libraries(${PROJECT_NAME}Test PRIVATE ${PROJECT_NAME} PRIVATE SDL2::SDL2 PRIVATE SDL2_image::SDL2_image PRIVATE SDL2_ttf::SDL2_ttf PRIVATE SDL2_mixer::SDL2_mixer)
endif (ADDEXE)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

FILE(GLOB_RECURSE header_list "src/*.hpp")
install(FILES ${header_list} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/../cmake/${PROJECT_NAME}
)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        VERSION 0.0.1
        COMPATIBILITY AnyNewerVersion)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/../cmake/${PROJECT_NAME}
)