#pragma once
#include "transaction.hpp"
#include "semaphore.hpp"
#include "BankAccount.hpp"
#include "user.hpp"
#include "ithread.hpp"
#include <unistd.h>
#include <iostream>
semaphore s;


 Transaction::Transaction(unsigned int amount, User* receiver, User* sender){
     _amount=amount;
     _receiver=receiver;    
     _sender=sender;
     _status = PENDING;
     std::cout << "Invoking transaction.\n";
     this->invoke();
 }

 bool Transaction::invoke(){
     BankAccount* recv_acc = _receiver->getAccount();
     std::cout << "Reached critical section.\n";
     s.wait();
     try{
       sleep(2);
     }catch(int n){
         std::cout << "Catching.\n";
         this->decline();
     }
     s.signal();
     std::cout << "Transaction completed.\n";
 }


 void Transaction::decline(){
     std::cout << "Declining.\n";
 }