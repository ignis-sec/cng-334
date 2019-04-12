#pragma once
#include <string>
#include "transaction.hpp"
#include <vector>

class BankAccount;

class User{
public:
    User(std::string name);

    const unsigned int _userid;
    Transaction *requestTransaction(unsigned int amount, User *recipent);
    BankAccount* getAccount();
private:
   std::string _name; 
   std::string _surname;
   std::vector<Transaction> transactionList; 
   BankAccount* _acc;
};