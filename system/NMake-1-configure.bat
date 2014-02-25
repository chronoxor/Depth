@echo off
mkdir build
cd build
copy ..\configure\Depth.txt CMakeLists.txt
cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=. .
cd ..
@echo on