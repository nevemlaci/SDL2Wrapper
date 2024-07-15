# cppSDL2
A simple library that wraps SDL2 into C++ classes for easier integration into C++ code

## Build
Prerequisited: cmake, Ninja or Visual Studio 17 2022, a C/C++ compiler(MSVC, MinGW for Windows, GNU GCC for Linux), Python

```
git clone https://github.com/nevemlaci/cppSDL2
cd cppSDL2
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
