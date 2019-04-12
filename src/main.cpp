#pragma once
#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include "user.hpp"
#include "transaction.hpp"
#include "semaphore.hpp"
#include <vector>
#define MAX_THREADS 155

//temp
#include <unistd.h>


std::mutex mtx;


semaphore t; 
User r("Rec");


void test(int id){
	std::cout << "Sleeping in non-critical\n";
	sleep(1);
	t.wait();
	std::cout << "Sleeping in critical\n"; 
	sleep(1);
	t.signal();
}




void handleInput(User u){
	char ch;
	std::vector<std::thread*> threads;
	std::cout << "Something!\n";
	while(1){
		std::cin >> ch;
		if(ch=='A') threads.push_back(new std::thread(&User::requestTransaction, u, 100, &r));
		for(auto &t : threads){
			t->join();
		}
	}
  
} 


int main(int argc, char *argv[]) {

	std::thread threads[MAX_THREADS];
	int counter = 0;
	//for(auto &t : threads){
	//	t = std::thread(test, counter++);
	//}

	//syncronize termination
	//for(auto &t : threads){
	//	t.join();
	//}
	User u("ata");
	handleInput(u);

	return 0;
}