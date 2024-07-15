from os import system
from sys import platform

if __name__ == "__main__":
    system("git submodule update --init --recursive")

    if platform == "linux" or platform == "linux2" or platform == "darwin":
        system("cd ./external/vcpkg ; ./bootstrap-vcpkg.sh")
    elif platform == "win32":
        system("dir & cd .\\external\\vcpkg & bootstrap-vcpkg.bat")

    print("Press enter to exit: ...")
    input()



