CC=g++
CPPFLAGS=-std=c++17
OUTPUT=kshksw
SRCS=./srcs/*

all:
	$(CC) $(CPPFLAGS) -m32 -o $(OUTPUT) $(SRCS)

debug:
	$(CC) $(CPPFLAGS) -g -m32 -o $(OUTPUT)-debug $(SRCS)