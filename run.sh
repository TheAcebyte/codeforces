#!/bin/bash

g++ main.cpp --std=c++17 -Wall -Wextra -Iinclude -o main
./main
rm main
