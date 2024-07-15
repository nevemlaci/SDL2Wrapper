from os import system
from sys import platform

if __name__ == "__main__":
    #Get git submodules
    system("git submodule update --init --recursive")

    #Run the platform appropriate vcpkg bootstrap
    if platform == "linux" or platform == "linux2" or platform == "darwin":
        system("cd ./external/vcpkg ; ./bootstrap-vcpkg.sh")
    elif platform == "win32":
        system("dir & cd .\\external\\vcpkg & bootstrap-vcpkg.bat")

    print("Press enter to exit: ...")
    input()



