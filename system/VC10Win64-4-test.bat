@echo off
cd build
MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="Debug" /p:Platform="x64"
rem MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="Release" /p:Platform="x64"
rem MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="MinSizeRel" /p:Platform="x64"
rem MSBuild.exe RUN_TESTS.vcxproj /p:Configuration="RelWithDebInfo" /p:Platform="x64"
cd ..
@echo on