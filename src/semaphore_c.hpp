#pragma once
#include "semaphore.hpp"
#include <unistd.h>





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





class Semaphore_c : public semaphore{
public:
    Semaphore_c(unsigned int __timeoutms, void (*callback));
    Semaphore_c(unsigned int __timeoutms);
    int wait();
    void timeout();
private:
    unsigned int _timeoutms;
};