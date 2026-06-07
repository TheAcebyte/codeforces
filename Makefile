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

restore:
	git restore main.cpp input.txt

.PHONY: all build run debug clean restore
