@echo off
cd build
mingw32-make -j 8 examples
cd ..
@echo on