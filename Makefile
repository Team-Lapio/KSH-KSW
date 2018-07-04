CC=g++
CPPFLAGS=-std=c++17
OUTPUT=kshksw
SRCS=./srcs/*

all:
	$(CC) $(CPPFLAGS) -o $(OUTPUT) $(SRCS)