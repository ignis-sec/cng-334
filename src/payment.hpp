#pragma once
#include "transaction.hpp"

//Class for inter-account money transfers.

class Payment : public Transaction{
public:
    Payment(unsigned int amount, User* receiver, User* sender);
    bool invoke();
private:
    User* _to;
};

