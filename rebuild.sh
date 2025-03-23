#!/bin/bash
set -e  

rm -rf build

BUILD_DIR="build"

mkdir -p $BUILD_DIR

cmake -S . -B $BUILD_DIR
cmake --build $BUILD_DIR

ctest --test-dir build
