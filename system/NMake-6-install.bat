@echo off
cd build
nmake -j 8 install
cd ..
@echo on