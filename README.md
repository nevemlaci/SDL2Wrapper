# cppSDL2
A simple library that wraps SDL2 into C++ classes for easier integration into C++ code

## Build
Prerequisited: cmake, Ninja or Visual Studio 17 2022, a C/C++ compiler(MSVC, MinGW for Windows, GNU GCC for Linux), Python

```
git clone https://github.com/nevemlaci/cppSDL2
cd cppSDL2
py ./bootstrap.py
cmake -S . --preset=<preset-name>
cmake --build build/<preset-name>_build
```

### Presets:
#### Windows:
*Using Ninja + MinGW*
```
gcc-win-debug
gcc-win-release
gcc-win-relwithdebinfo
```

*Using Visual Studio 17 2022 + MSVC*
```
msvc-debug
msvc-release
msvc-relwithdebinfo
```

#### Linux:
*Using Ninja + GNU GCC*
```
gcc-linux-debug
gcc-linux-release
gcc-linux-relwithdebinfo
```

## Installing
After building:
```
cmake --install build/<preset-name>_build
```

In your CMakeList.txt:

```
find_package(cppSDL REQUIRED)
add_executable(MyExe main.cpp)
target_link_libraries(MyExe PRIVATE cppSDL::cppSDL)
```

You should also link SDL2, SDL2_image, SDL2_ttf, SDL2_mixer in some way. I recommend [setting up vcpkg](https://learn.microsoft.com/en-us/vcpkg/users/buildsystems/cmake-integration) to get the dependencies for you. You can check the vcpkg setup of this repo for reference aswell.
