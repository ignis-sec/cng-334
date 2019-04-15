#pragma once
#include "transaction.hpp"
#include <iostream>

//BASE Class only, not to be used by itself. Instead, check payment.hpp and withdrawal.hpp

Transaction::Transaction(){
    _status= PENDING;
}

 void Transaction::decline(){
     std::cout << "Declining.\n";
     _status = DECLINED;
 }


 void Transaction::finalize(){
    std::cout << "Transaction completed.\n";
    _status = COMPLETED;
 }