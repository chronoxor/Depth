@echo off
cd build
make -j 8 tests
cd ..
@echo on