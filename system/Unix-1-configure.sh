#!/bin/bash

mkdir ./build
cd ./build
cp ../configure/Depth.txt ./CMakeLists.txt
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=. .
cd ..
