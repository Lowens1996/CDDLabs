#Author: Lee Owens
#Simple makefile 

Executable: Signal.o Semaphore.o #creates executable file called barrier using object files from below
	g++ -std=c++11 -pthread signal.o Semaphore.o -o signal

Signal.o: signal.cpp #Main program file 
	g++ -std=c++11 -pthread -c signal.cpp

Semaphore.o: Semaphore.cpp Semaphore.h #other cpp files and header files in this case will always be Semaphore.cpp & .h
	g++ -std=c++11 -pthread -c Semaphore.cpp	        

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o #remove all object files 
