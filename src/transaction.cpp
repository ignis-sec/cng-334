#pragma once
#include "transaction.hpp"
#include "semaphore.hpp"
#include "BankAccount.hpp"
#include "user.hpp"
semaphore s;

 Transaction::Transaction(unsigned int amount, User* receiver, User* sender){
     _amount=amount;
     _receiver=receiver;
     _sender=sender;
     _status = PENDING;
 }

 bool Transaction::invoke(){
     BankAccount* recv_acc = _receiver->getAccount();
     s.wait();
     s.signal();
 }