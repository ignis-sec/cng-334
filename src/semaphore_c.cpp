#include "semaphore_c.hpp"
#include "ithread.hpp"
#include <iostream>


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