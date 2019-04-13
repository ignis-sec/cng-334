#pragma once
#include "transaction.hpp"
#include "semaphore.hpp"
#include "BankAccount.hpp"
#include "user.hpp"
#include "ithread.hpp"
#include "semaphore_c.hpp"
#include <unistd.h>
#include <iostream>
Semaphore_c s(1000);


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
     try{
        if(s.wait()) throw(1);
        sleep(2);
        s.signal();
        std::cout << "Transaction completed.\n";
     }catch(int n){
        std::cout << "Catching.\n";
        this->decline();
     }
 }


 void Transaction::decline(){
     std::cout << "Declining.\n";
 }