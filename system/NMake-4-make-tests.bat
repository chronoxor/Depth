@echo off
cd build
nmake -j 8 tests
cd ..
@echo on