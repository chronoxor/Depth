@echo off
cd build
vcbuild /time INSTALL.vcproj "Debug|Win32"
rem vcbuild /time INSTALL.vcproj "Release|Win32"
rem vcbuild /time INSTALL.vcproj "MinSizeRel|Win32"
rem vcbuild /time INSTALL.vcproj "RelWithDebInfo|Win32"
cd ..
@echo on