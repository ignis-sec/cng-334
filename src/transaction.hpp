#pragma once
#include "semaphore.hpp"

//BASE Class only, not to be used by itself. Instead, check payment.hpp and withdrawal.hpp



#define TRANSACT_MAX_DELAY 1000 
//if a transaction hangs for more than 1 second, decline it
//Max delay is not used becuase it was intended for semaphore_c class (semaphore with timeout callback)

class User;
enum status {PENDING, INITIALIZED, COMPLETED, DECLINED};

class Transaction{
public:
    Transaction();
    void decline();
    bool invoke();
    void finalize();
protected:
    unsigned int _amount;
    User* _owner;
    status _status;
};