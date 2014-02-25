@echo off
cd build
vcbuild /time full.sln "Debug|Win32"
rem vcbuild /time full.sln "Release|Win32"
rem vcbuild /time full.sln "MinSizeRel|Win32"
rem vcbuild /time full.sln "RelWithDebInfo|Win32"
cd ..
@echo on