#pragma once
#include <unistd.h>
#include <iostream>
#include "payment.hpp"
#include "semaphore.hpp"
#include "user.hpp"
#include "ithread.hpp"
#include "semaphore_c.hpp"
#include "bankAccount.hpp"
#include "meta.h"

//semaphore for the payment mutual exclusive read/write
semaphore sp;

 Payment::Payment(unsigned int amount, User* receiver, User* sender){
     _amount=amount;
     _owner=receiver;    
     _to=sender;
     _status = PENDING;
     std::cout << "Invoking transaction.\n";
     this->invoke();//Start processing the transaction
 }
//Start the processing of a transaction. Called immediately after constructor.
bool Payment::invoke(){
     try{
        #ifdef SERIAL_WAIT
            sleep(SERIAL_WAIT_TIME);
        #endif

        #ifdef VERBOSE
        std::cout << "Reached critical section.\n";
        #endif
        //wait for other threads to finish critical section
        #if SUBMISSION_WEEK>2
        sp.wait();
        #endif
        //Status can be used to to classify ongoing transactions in the transaction table (Not implemented yet)
        _status = INITIALIZED;
        //deduct from owners account
        float new_balance= _owner->getAccount()->changeBalance(-1.0*_amount);
        std::cout << "New balance for sender is: " << new_balance << std::endl;

        //add to the target users account
        new_balance= _to->getAccount()->changeBalance(_amount);
        std::cout << "New balance receiver is: " << new_balance << std::endl;

        //signal end of critical section
        #if SUBMISSION_WEEK>2
        sp.signal();
        #endif

        //finalize the transaction with Transaction::finalize()
        finalize();
     }catch(int n){
        std::cout << "An error has occured.\n";
        this->decline();
     }
 }



