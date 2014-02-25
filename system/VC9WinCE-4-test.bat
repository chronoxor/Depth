@echo off
cd build
vcbuild /time RUN_TESTS.vcproj "Debug|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time RUN_TESTS.vcproj "Release|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time RUN_TESTS.vcproj "MinSizeRel|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time RUN_TESTS.vcproj "RelWithDebInfo|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
cd ..
@echo on