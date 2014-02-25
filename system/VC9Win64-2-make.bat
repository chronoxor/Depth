@echo off
cd build
vcbuild /time full.sln "Debug|x64"
rem vcbuild /time full.sln "Release|x64"
rem vcbuild /time full.sln "MinSizeRel|x64"
rem vcbuild /time full.sln "RelWithDebInfo|x64"
cd ..
@echo on