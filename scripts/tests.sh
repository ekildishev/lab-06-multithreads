#! /bin/sh
set -e

cmake -H. -B_builds $CMAKE_OPTS
cmake --build _builds
cmake --build _builds --target test -- ARGS="--verbose"
