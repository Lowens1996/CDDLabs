#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
/*Author:Lee Owens Last Edit Date: 24/10/2017*/

int count= 0; //keep count of threads 
int numOfThreads = 5; //thread pool size (used to compare against count) 

void Task(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int count)
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
  std::thread Thread;
  std::vector<std::thread> threadPool;
  std::shared_ptr<Semaphore> barrier1( new Semaphore (0));
  std::shared_ptr<Semaphore> barrier2( new Semaphore (0));
  std::shared_ptr<Semaphore> mutex( new Semaphore (1));
 
  //create thread vector  
  for(int index=0; index <= numOfThreads; index++)
    {
      threadPool.push_back(Thread);
    }
  //send threads to barrier
  for(int index=0; index <= threadPool.size(); index++)
    {
      threadPool[index]=std::thread(mutex,barrier1,barrier2,count);
    }
  //join threads back to main
  for(int index=0; index <= threadPool.size(); index++)
    {
      threadPool[index].join();
    }
  return 0;
}
