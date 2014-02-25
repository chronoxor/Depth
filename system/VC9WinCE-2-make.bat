@echo off
cd build
vcbuild /time full.sln "Debug|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time full.sln "Release|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time full.sln "MinSizeRel|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
rem vcbuild /time full.sln "RelWithDebInfo|Windows Mobile 5.0 Pocket PC SDK (ARMV4I)"
cd ..
@echo on