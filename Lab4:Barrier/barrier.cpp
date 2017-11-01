#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
/*Author:Lee Owens Last Edit Date: 01/11/2017*/

int count= 0; //keep count of threads 
int numOfThreads = 5; //thread pool size (used to compare against count) 

void Task( std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2)
{

  std::cout <<"thread is entering ";
  mutex->Wait();
  count++;
  std::cout <<"count is now " << count;
  if(count == numOfThreads)
    {
      barrier2->Wait();
      barrier1->Signal();
    }
  mutex->Signal();
  barrier1->Wait();
  barrier2->Signal();

  std::cout <<"thread in critical section";
    
  mutex->Wait();
  std::cout <<"thread leaveing";
  count--;
  std::cout <<"count is now " << count;
  if(count == 0)
    {
      barrier1->Wait();
      barrier2->Signal();
    }
  mutex->Signal();
  barrier2->Wait();
  barrier1->Signal();
}//task

int main(void){
  int index =0; //loop index 
  std::shared_ptr<Semaphore> barrier1( new Semaphore);
  std::shared_ptr<Semaphore> barrier2( new Semaphore);
  std::shared_ptr<Semaphore> mutex( new Semaphore (1));
  std::vector<std::thread> threadPool; //thread vector
  
  for(index=0; index<=numOfThreads; index++)
    {
       std::thread Thread;
       Thread=std::thread(Task,mutex,barrier1,barrier2);
    }
  for(index=0; index<=numOfThreads; index++)
    {
      Thread.join();
    }
 
  /*create thread vector  
  for(int index=0; index <= numOfThreads; index++)
    {
      std::thread Thread;
      threadPool.push_back(Thread);
    }
  //send threads to barrier
  for(int index=0; index <= threadPool.size(); index++)
    {
      threadPool[index]=std::thread(Task,mutex,barrier1,barrier2);
    }
  //join threads back to main
  for(int index=0; index <= threadPool.size(); index++)
    {
      threadPool[index].join();
      }*/
  return 0;
}
