#include "semaphore_c.hpp"
#include <thread>


Semaphore_c::Semaphore_c(unsigned int __timeoutms, void *(callback)){
    _timeoutms = __timeoutms;
    //std::thread();

}