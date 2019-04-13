#pragma once
#include "semaphore.hpp"
#include <iostream>

void semaphore::signal(){
    std::lock_guard<std::mutex> lock(_mutex);
    ++_count;
    _condition.notify_one();
}

bool semaphore::try_wait(){
    std::lock_guard<std::mutex> lock(_mutex);
    if(_count) {
        --_count;
        return true;
    }
    return false;
}

void semaphore::wait(){
    std::unique_lock<std::mutex> lock(_mutex);
        while(!_count) _condition.wait(lock);
        --_count;
}
