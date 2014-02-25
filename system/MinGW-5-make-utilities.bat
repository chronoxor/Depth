@echo off
cd build
mingw32-make -j 8 utilities
cd ..
@echo on