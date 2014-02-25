@echo off
cd build
MSBuild.exe INSTALL.vcxproj /p:Configuration="Debug" /p:Platform="Win32"
rem MSBuild.exe INSTALL.vcxproj /p:Configuration="Release" /p:Platform="Win32"
rem MSBuild.exe INSTALL.vcxproj /p:Configuration="MinSizeRel" /p:Platform="Win32"
rem MSBuild.exe INSTALL.vcxproj /p:Configuration="RelWithDebInfo" /p:Platform="Win32"
cd ..
@echo on