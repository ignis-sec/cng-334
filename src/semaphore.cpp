#pragma once
#include <iostream>
#include "semaphore.hpp"

//My take on the semaphores using mutex and condition variable.


//Signal critical section done
void semaphore::signal(){
    std::lock_guard<std::mutex> lock(_mutex);
    ++_count;
    _condition.notify_one();
}

//Not used, doesnt work properly yet.
bool semaphore::try_wait(){
    std::lock_guard<std::mutex> lock(_mutex);
    if(_count) {
        --_count;
        return true;
    }
    return false;
}

//Wait for other criticals.
void semaphore::wait(){
    std::unique_lock<std::mutex> lock(_mutex);
        while(!_count) _condition.wait(lock);
        --_count;
}
