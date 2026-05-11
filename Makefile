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

compile-docs:
	latexmk -pdf docs.tex
	latexmk -c docs.tex

clean-docs:
	latexmk -C docs.tex

.PHONY: all build run debug clean compile-docs clean-docs
