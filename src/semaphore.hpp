#pragma once
#include <mutex>
#include <condition_variable>

//My take on the semaphores using mutex and condition variable.

class semaphore
{
protected:
    std::mutex _mutex;
    std::condition_variable _condition;
    unsigned long _count = 1;
public:
    void signal();
    bool try_wait();
    void wait();

};