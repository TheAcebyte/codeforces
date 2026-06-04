CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: run clean

build:
	$(CXX) $(CXXFLAGS) -o main main.cpp

run: build
	./main

debug: build
	gdb main

clean:
	rm -f main

.PHONY: all build run debug clean
