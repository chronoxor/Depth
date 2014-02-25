@echo off
cd build
vcbuild /time INSTALL.vcproj "Debug|x64"
rem vcbuild /time INSTALL.vcproj "Release|x64"
rem vcbuild /time INSTALL.vcproj "MinSizeRel|x64"
rem vcbuild /time INSTALL.vcproj "RelWithDebInfo|x64"
cd ..
@echo on