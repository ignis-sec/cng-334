#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

#include "semaphore.hpp"

#define MAX_THREADS 15

//temp
#include <unistd.h>


std::mutex mtx;


semaphore t;

void test(int id){
	std::cout << "Sleeping in non-critical\n";
	sleep(1);
	t.wait();
	std::cout << "Sleeping in critical\n";
	sleep(1);
	t.signal();
}

int main(int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;
	
	std::thread threads[MAX_THREADS];
	int counter = 0;
	//spawn thread pool
	for(auto &t : threads){
		t = std::thread(test, counter++);
	}

	//syncronize termination
	for(auto &t : threads){
		t.join();
	}
	return 0;
}