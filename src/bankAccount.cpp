#pragma once
#include "bankAccount.hpp"
#include "meta.h"
#include <unistd.h>
unsigned int _maxbankid=0;

//automatically id as the next value available
BankAccount::BankAccount(int balance, User* owner):__id(++_maxbankid){
    _owner = owner;
    accountBalance=balance;
}

//add/remove the difference from current account
float BankAccount::changeBalance(float difference){
    float newBalance = accountBalance+difference;
        #ifdef TRANSACTION_WAIT
            sleep(TRANSACTION_WAIT_TIME);
        #endif
    accountBalance = newBalance;
    return accountBalance;
}