@echo off
cd build
mingw32-make -j 8 Doxygen
cd ..
@echo on