#!/bin/sh
set -ex

cmake -H. -B_builds
cmake --build _builds
cmake ./_builds/template