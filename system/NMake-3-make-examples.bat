@echo off
cd build
nmake -j 8 examples
cd ..
@echo on