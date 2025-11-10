#!/bin/bash

g++ main.cpp --std=c++17 -DDEBUG -Wall -Wextra -Iinclude -o main
./main
rm main
