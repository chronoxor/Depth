@echo off
cd build
nmake -j 8 Doxygen
cd ..
@echo on