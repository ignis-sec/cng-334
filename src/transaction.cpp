#pragma once
#include "transaction.hpp"


 Transaction::Transaction(unsigned int amount, User* receiver, User* sender){
     _amount=amount;
     _receiver=receiver;
     _sender=sender;
     _status = PENDING;
 }