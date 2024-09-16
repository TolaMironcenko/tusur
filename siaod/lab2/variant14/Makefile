CXX=g++
CXXFLAGS=-Wall -std=c++11 -Wno-sign-compare
SOURCES=src/main.cpp
TARGET=bin/main

default: all

all: build

build:
	@if [ ! -d bin ]; then \
		mkdir bin; \
	fi
	$(CXX) -o $(TARGET) $(SOURCES) $(CXXFLAGS)

clean:
	@if [ -d bin ]; then \
		rm -rv bin; \
	fi
