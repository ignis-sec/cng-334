#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>

#define MAX_THREADS 15

std::mutex mtx;

void test(int id){
	std::unique_lock<std::mutex> lck (mtx,std::defer_lock);
	//Lock critical section
	lck.lock();
	std::cout << "bar" << id << "\n";
	//release spinlock
	lck.unlock();
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