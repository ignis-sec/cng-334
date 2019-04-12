#pragma once
class User;

enum status {PENDING, INITIALIZED, COMPLETED, DECLINED};

class Transaction{
public:

    Transaction(unsigned int amount, User* receiver, User* sender);
    bool invoke();
    void decline();
    void finalize();
 
private:
    unsigned int _amount;
    User* _receiver; 
    User* _sender;
    status _status;
};