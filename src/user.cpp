#pragma once
#include <iostream>
#include "user.hpp"
#include "transaction.hpp"

unsigned int _maxid=0;

User::User(std::string name):_userid(++_maxid){
    _name = name;
}


 Transaction* User::requestTransaction(unsigned int amount, User *recipent){
    Transaction *t = new Transaction(amount, recipent, this);
    std::cout <<"New transaction requested.\n";
    return t;
 }

 BankAccount* User::getAccount(){
     return _acc;
 }