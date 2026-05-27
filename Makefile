CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: run clean

build:
	$(CXX) $(CXXFLAGS) -o main main.cpp

debug: build
	gdb main

run: build
	./main

clean:
	rm -f main

.PHONY: all build run debug clean
