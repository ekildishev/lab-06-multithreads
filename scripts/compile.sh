#!/bin/sh
set -ex

cmake -H. -B_builds
cmake --build _builds
./_builds/template 4
./_builds/template