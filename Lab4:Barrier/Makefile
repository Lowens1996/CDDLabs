#Author: Lee Owens

CC=g++
CFLAGS= -std=c++11 -pthread
Header= Semaphore.h
CPPFILES= Semaphore.cpp barrier.cpp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(Header) $(CPPFILES)
	$(CC) -o barrier  $(CFLAGS) $(DEBUGFLAGS) $(Header) $(CPPFILES)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL


CLEAN:
	rm *.o
