@echo off
cd build
MSBuild.exe INSTALL.vcxproj /p:Configuration="Debug" /p:Platform="x64"
rem MSBuild.exe INSTALL.vcxproj /p:Configuration="Release" /p:Platform="x64"
rem MSBuild.exe INSTALL.vcxproj /p:Configuration="MinSizeRel" /p:Platform="x64"
rem MSBuild.exe INSTALL.vcxproj /p:Configuration="RelWithDebInfo" /p:Platform="x64"
cd ..
@echo on