@echo off
cd build
nmake -j 8 test
cd ..
@echo on