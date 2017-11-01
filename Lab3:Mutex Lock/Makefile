#Author: Lee Owens
#Simple makefile 

Executable: Mutex.o Semaphore.o #creates executable file called mutex using object files from below
	g++ -std=c++11 -pthread mutex.o Semaphore.o -o mutex

Mutex.o: mutex.cpp #Main program file 
	g++ -std=c++11 -pthread -c mutex.cpp

Semaphore.o: Semaphore.cpp Semaphore.h #other cpp files and header files in this case will always be Semaphore.cpp & .h
	g++ -std=c++11 -pthread -c Semaphore.cpp	        

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o #remove all object files 
