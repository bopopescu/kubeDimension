#!/bin/bash
cd ../build
rm -fR *
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j12
cd ../bin
kill `ps -ef | grep find_object | grep -v grep | awk '{print $2}'`
./find_object --config ../config/maxfactor8.ini --objects ../products/logos-samples/logos_forbes --debug &
