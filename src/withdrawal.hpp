#pragma once
#include "transaction.hpp"

//Class for withdrawing from your own account

class Withdrawal : public Transaction{

public:
    Withdrawal(unsigned int amount, User* owner);
    bool invoke();

};

