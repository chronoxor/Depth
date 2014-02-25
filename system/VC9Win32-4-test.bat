@echo off
cd build
vcbuild /time RUN_TESTS.vcproj "Debug|Win32"
rem vcbuild /time RUN_TESTS.vcproj "Release|Win32"
rem vcbuild /time RUN_TESTS.vcproj "MinSizeRel|Win32"
rem vcbuild /time RUN_TESTS.vcproj "RelWithDebInfo|Win32"
cd ..
@echo on