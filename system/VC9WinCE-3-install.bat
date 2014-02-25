@echo off
cd build
vcbuild /time INSTALL.vcproj "Debug|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time INSTALL.vcproj "Release|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time INSTALL.vcproj "MinSizeRel|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time INSTALL.vcproj "RelWithDebInfo|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
cd ..
@echo on