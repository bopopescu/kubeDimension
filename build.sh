#!/bin/bash

cd /src/app

# Clone Bag of Words2 with segmentation templates
# Checkcout the RootSift version
cd /src/app/lib/DLib
rm -fR build
mkdir build
cmake ..
make -j8

# Build the executables for DBow2
cd /src/app/rest
rm -fR build
mkdir build 
cmake ..
make -j8

# Build the executable for Pastec/Rest Api
cd /src/app/lynx/
rm -fR build
mkdir build
cd build
cmake ..
make -j8
make install
