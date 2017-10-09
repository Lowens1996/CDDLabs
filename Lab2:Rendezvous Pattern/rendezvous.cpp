#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout << "A1"<<std::endl;
  aArrived->Signal();
  bArrived->Wait();
  std::cout << "A2"<<std::endl;
  
}
void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout << "B1"<<std::endl;
  bArrived->Signal();
  aArrived->Wait();
  std::cout << "B2"<<std::endl;
}

int main(void){
  std::thread threadA, threadB;
  std::shared_ptr<Semaphore> aArrived( new Semaphore);
  std::shared_ptr<Semaphore> bArrived( new Semaphore);
  /**< Launch the threads  */
  threadA=std::thread(taskTwo,aArrived,bArrived);
  threadB=std::thread(taskOne,aArrived,bArrived);
  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  return 0;
}
