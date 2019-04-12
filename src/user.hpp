#pragma once
#include <string>
#include <vector>


class Transaction;
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