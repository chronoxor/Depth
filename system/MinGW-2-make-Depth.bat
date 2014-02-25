@echo off
cd build
mingw32-make -j 8 Depth
cd ..
@echo on