#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> mutex, int count){
  mutex->Wait();
  /**critical section*/
  std::cout << "thread A is in the critical section"<<std::endl;
  count = count +1;
  mutex->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> mutex, int count){
   mutex->Wait();
  /**critical section*/
  std::cout << "thread B is in the critical section"<<std::endl;
  count = count +1;
  mutex->Signal();
}

int main(void){
  std::thread threadA, threadB;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  int count = 0;
  /**< Launch the threads  */
  threadA=std::thread(taskOne,mutex,count);
  threadB=std::thread(taskTwo,mutex,count);
  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  return 0;
}
