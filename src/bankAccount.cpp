#pragma once
#include "bankAccount.hpp"


unsigned int _maxbankid=0;

//automatically id as the next value available
BankAccount::BankAccount(int balance, User* owner):__id(++_maxbankid){
    _owner = owner;
    accountBalance=balance;
}

//add/remove the difference from current account
float BankAccount::changeBalance(float difference){
    accountBalance+=difference;
    return accountBalance;
}