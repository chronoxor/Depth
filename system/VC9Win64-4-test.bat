@echo off
cd build
vcbuild /time RUN_TESTS.vcproj "Debug|x64"
rem vcbuild /time RUN_TESTS.vcproj "Release|x64"
rem vcbuild /time RUN_TESTS.vcproj "MinSizeRel|x64"
rem vcbuild /time RUN_TESTS.vcproj "RelWithDebInfo|x64"
cd ..
@echo on