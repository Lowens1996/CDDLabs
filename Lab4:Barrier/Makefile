#Author: Lee Owens
#Simple makefile 

Executable: Barrier.o Semaphore.o #creates executable file called barrier using object files from below
	g++ Barrier.o Semaphore.o -o barrier #compile object files together to create executable 

Barrier.o: barrier.cpp #Main program file 
	g++ -c barrier.cpp

Semaphore.o: Semaphore.cpp Semaphore.h #other cpp files and header files in this case will always be
	g++ -c Semaphore.cpp	       #Semaphore.cpp & .h 

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o #remove all object files 
