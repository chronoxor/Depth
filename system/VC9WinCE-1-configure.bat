@echo off
mkdir build
cd build
copy ..\configure\Depth.txt CMakeLists.txt
cmake -G "Visual Studio 9 2008" -DCMAKE_TOOLCHAIN_FILE=..\configure\Toolchain-WindowsMobile-cl.cmake -DCMAKE_INSTALL_PREFIX=. .
cd ..
@echo on