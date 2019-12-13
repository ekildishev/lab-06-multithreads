#!/bin/bash
set -e

files=`find . -name "*.cpp" -or -name "*.hpp" -or -name ".h" | grep -v "./tools/*" | grep -v "PicoSHA2"`
filter=-build/c++11,-runtime/references,-whitespace/braces,-whitespace/indent,-whitespace/comments,-build/include_order,-runtime/threadsafe_fn,-legal/copyright
echo $files | xargs cpplint --filter=$filter

