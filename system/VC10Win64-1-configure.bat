@echo off
mkdir build
cd build
copy ..\configure\Depth.txt CMakeLists.txt
cmake -G "Visual Studio 10 Win64" -DCMAKE_INSTALL_PREFIX=. .
cd ..
@echo on