@echo off
cd build
mingw32-make -j 8 tests
cd ..
@echo on