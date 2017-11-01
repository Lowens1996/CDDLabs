#Author: Lee Owens
#Simple makefile 

Executable: Rendezvous.o Semaphore.o #creates executable file called barrier using object files from below
	g++ -std=c++11 -pthread rendezvous.o Semaphore.o -o rendezvous

Rendezvous.o: rendezvous.cpp #Main program file 
	g++ -std=c++11 -pthread -c rendezvous.cpp

Semaphore.o: Semaphore.cpp Semaphore.h #other cpp files and header files in this case will always be Semaphore.cpp & .h
	g++ -std=c++11 -pthread -c Semaphore.cpp	        

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o #remove all object files 
