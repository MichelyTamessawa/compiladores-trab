#!/bin/bash

cd build
make
cd ..
./sc -i test.s