#pragma once
#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <vector>
#include "user.hpp"
#include "transaction.hpp"
#include "semaphore.hpp"
#include "ithread.hpp"
#include "bankAccount.hpp"

#define MAX_THREADS 155

//Ata Hakçıl 2243467
//Tested on Linux 4.19.0
//SMP Debian 4.19.13 (2019-01-03) x86_64 GNU/Linux



//Initialize test accounts
User *u;
User *r;

//Globals
std::mutex mtx;
semaphore t; 


//Handle current stdin testing
void handleInput(User *u){
	char ch;
	//Vector of ithread references
	std::vector<std::thread*> threads;
	std::cout << "Listening stdin for input. A for payment to receviertest, B for withdrawal.\n";
	std::cout << "Try AAA.. or BBBBBB... for parallel execution.\n";
	while(1){
		std::cin >> ch;
		if(ch=='A') threads.push_back(new ithread(&User::requestPayment, u, 100, r));
		if(ch=='B') threads.push_back(new ithread(&User::requestWithdraw, u, 100));
	}
  
} 


int main(int argc, char *argv[]) {

	//Construct and allocate users along with bank accounts
	u = new User("ata", new BankAccount(100000,u));
	r = new User("receivertest", new BankAccount(100,r));

	handleInput(u);//doesn't terminate because of the io loop
	return 0;
}