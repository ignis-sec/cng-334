#pragma once
#include <string>
#include <vector>

class Transaction;
class Payment;
class Withdrawal;
class BankAccount;

class User{
public:
    User(std::string name);
    User(std::string name, BankAccount* __acc);
    const unsigned int _userid;
    Payment *requestPayment(unsigned int amount, User *recipent);
    Withdrawal *requestWithdraw(unsigned int amount);
    BankAccount* getAccount();
    void setAccount(BankAccount* __acc);
private:
    std::string _name;
    std::vector<Transaction*> transactionList; 
    std::string _surname;
    BankAccount* _acc;
};