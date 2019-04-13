#pragma once
#include "semaphore.hpp"
#include <unistd.h>




class Semaphore_c : public semaphore{
public:
    Semaphore_c(unsigned int __timeoutms, void (*callback));
    Semaphore_c(unsigned int __timeoutms);
    int wait();
    void timeout();
private:
    unsigned int _timeoutms;
};