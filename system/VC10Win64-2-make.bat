@echo off
cd build
MSBuild.exe full.sln /p:Configuration="Debug" /p:Platform="x64"
rem MSBuild.exe full.sln /p:Configuration="Release" /p:Platform="x64"
rem MSBuild.exe full.sln /p:Configuration="MinSizeRel" /p:Platform="x64"
rem MSBuild.exe full.sln /p:Configuration="RelWithDebInfo" /p:Platform="x64"
cd ..
@echo on