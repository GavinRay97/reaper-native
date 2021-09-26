#!/bin/bash
clang -shared -std=c++20 -fuse-ld=lld -I"../sdk" \
  reaper_plugin_functions_wrapper.cpp \
  -o reaper_wrapper.dll