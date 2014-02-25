@echo off
cd build
nmake -j 8 utilities
cd ..
@echo on