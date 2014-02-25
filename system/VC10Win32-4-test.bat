@echo off
cd build
MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="Debug" /p:Platform="Win32"
rem MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="Release" /p:Platform="Win32"
rem MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="MinSizeRel" /p:Platform="Win32"
rem MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="RelWithDebInfo" /p:Platform="Win32"
cd ..
@echo on