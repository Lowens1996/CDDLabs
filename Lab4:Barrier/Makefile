#Author: Lee Owens
#Simple makefile 

Executable: Barrier.o Semaphore.o #creates executable file called barrier using object files from below
	g++ -std=c++11 -pthread barrier.o Semaphore.o -o barrier

Barrier.o: barrier.cpp #Main program file 
	g++ -std=c++11 -pthread -c barrier.cpp

Semaphore.o: Semaphore.cpp Semaphore.h #other cpp files and header files in this case will always be Semaphore.cpp & .h
	g++ -std=c++11 -pthread -c Semaphore.cpp	        

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o #remove all object files 
