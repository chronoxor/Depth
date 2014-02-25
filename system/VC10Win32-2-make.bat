@echo off
cd build
MSBuild.exe full.sln /p:Configuration="Debug" /p:Platform="Win32"
rem MSBuild.exe full.sln /p:Configuration="Release" /p:Platform="Win32"
rem MSBuild.exe full.sln /p:Configuration="MinSizeRel" /p:Platform="Win32"
rem MSBuild.exe full.sln /p:Configuration="RelWithDebInfo" /p:Platform="Win32"
cd ..
@echo on