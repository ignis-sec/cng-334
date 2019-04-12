#pragma once
class User;

#define TRANSACT_MAX_DELAY 1000 
//if a transaction hangs for more than 1 second, decline it

enum status {PENDING, INITIALIZED, COMPLETED, DECLINED};

class Transaction{
public:

    Transaction(unsigned int amount, User* receiver, User* sender);
    void decline();
    bool invoke();
    void finalize();
 
private:
    unsigned int _amount;
    User* _receiver; 
    User* _sender;
    status _status;
};