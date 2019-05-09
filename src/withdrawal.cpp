#pragma once
#include "withdrawal.hpp"
#include "semaphore.hpp"
#include "user.hpp"
#include "ithread.hpp"
#include "semaphore_c.hpp"
#include <unistd.h>
#include <iostream>
#include "bankAccount.hpp"
#include "meta.h"

//semaphore for the payment mutual exclusive read/write
semaphore sw;

 Withdrawal::Withdrawal(unsigned int amount, User* owner){
     _owner=owner;    
     _amount=amount;
     _status = PENDING;
     std::cout << "Invoking transaction.\n";
     this->invoke();//Start processing the transaction
 }



bool Withdrawal::invoke(){
     try{
        #ifdef VERBOSE
        std::cout << "Reached critical section.\n";
        #endif
        //wait for other threads to finish critical section
        #if SUBMISSION_WEEK>2
            sw.wait();
        #endif
        //Status can be used to to classify ongoing transactions in the transaction table (Not implemented yet)
        _status = INITIALIZED;
        //deduct from owners account
        float new_balance= _owner->getAccount()->changeBalance(-1.0*_amount);
        std::cout << "New balance is: " << new_balance << std::endl;

        //signal end of critical section
        #if SUBMISSION_WEEK>2
        sw.signal();
        #endif

        //finalize the transaction with Transaction::finalize()
        finalize();
     }catch(int n){
        std::cout << "An error has occured.\n";
        this->decline();
     }
 }



