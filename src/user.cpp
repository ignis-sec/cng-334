#pragma once
#include <iostream>
#include "user.hpp"
#include "payment.hpp"
#include "withdrawal.hpp"
#include "bankAccount.hpp"
#include "transaction.hpp"

unsigned int _maxid=0;//used for creating unique id for user

//Constructors
User::User(std::string __name, BankAccount *__acc):_userid(++_maxid){
    _acc = __acc;
    _name = __name;
}

User::User(std::string __name):_userid(++_maxid){
    _name = __name;
}
//


//request to make a payment to another account
 Payment* User::requestPayment(unsigned int amount, User *recipent){
    std::cout <<"New payment requested.\n";
    Payment *t = new Payment(amount, this,recipent);
    transactionList.push_back(t);
    return t;
 }


//Request to make a withdrawal from own account.
 Withdrawal* User::requestWithdraw(unsigned int amount){
    std::cout <<"New Withdraw requested.\n";
    Withdrawal *t = new Withdrawal(amount, this);
    transactionList.push_back(t);
    return t;
 }

 BankAccount* User::getAccount(){
     return _acc; 
 }

 void User::setAccount(BankAccount* __acc){
     _acc = __acc;
 }