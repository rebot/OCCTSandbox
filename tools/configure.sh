#!/bin/bash

if [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
    # Make sure you're chosing the MSYS generator
    cmake -G"MSYS Makefiles" -S . -B ./build
else
    # Default generator for Unix and MacOS (Darwin)
    cmake -S . -B ./build
fi
