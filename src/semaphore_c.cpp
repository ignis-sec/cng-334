#include "semaphore_c.hpp"
#include <iostream>
#include "ithread.hpp"




//THIS CLASS IS UNUSED SEE SEMAPHORE.HPP INSTEAD
//
//I tried to create a semaphore that had max wait time, and that would timeout after the interval has passed.
//This could be used as:
/*
try{
  if(s.wait()) throw;    
}
*/
//to check.
//Class does not function with %100 confidence, sometimes next thread hitting wait is being killed instead of the current one,
//And i found it to be too expensive to use with every operation.







Semaphore_c::Semaphore_c(unsigned int __timeoutms, void *(callback)){
    _timeoutms = __timeoutms;
    //std::thread();
}

Semaphore_c::Semaphore_c(unsigned int __timeoutms){
    _timeoutms = __timeoutms;
}

int Semaphore_c::wait(){
    std::cout << "sc: " << _count << "\n";
    std::unique_lock<std::mutex> lock(_mutex);
    ithread *t;
        while(_count==0){
            t = new ithread(&Semaphore_c::timeout, this);
            _condition.wait(lock);
        }   
        return --_count;
}
void Semaphore_c::timeout(){
    sleep(1);
    if(_count==0){
        _count=2;
        std::lock_guard<std::mutex> lock(_mutex);
        _condition.notify_one();
    }
}