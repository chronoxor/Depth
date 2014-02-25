@echo off
cd build
mingw32-make -j 8 test
cd ..
@echo on