@echo off
cd build
make -j 8 test
cd ..
@echo on