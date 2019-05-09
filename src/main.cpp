#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "user.hpp"
#include "transaction.hpp"
#include "semaphore.hpp"
#include "ithread.hpp"
#include "bankAccount.hpp"
#include "meta.h"

#define MAX_THREADS 155


//Ata Hakçıl 2243467

//Tested on Linux 4.19.0 and Windows 10 x64
//SMP Debian 4.19.13 (2019-01-03) x86_64 GNU/Linux
//10.0.17134 Build 17134 x64


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
	
	#if SUBMISSION_WEEK>=SOCKET_WEEK
		int sockfd, newsockfd, portno;
		socklen_t clilen;
		char buffer[256];
		struct sockaddr_in serv_addr, cli_addr;
		int n;
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0) std::cout <<("ERROR opening socket");
		bzero((char *) &serv_addr, sizeof(serv_addr));
		portno = 8080;
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);
		std::cout << "Binding to port" << std::endl;
		if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
			std::cout <<("ERROR on binding, exiting") << std::endl;
			return;
		}
		else std::cout << "Bind Succesful." << std::endl;
		//listen again on broken
		int listenflag = -1;
		while(1){
			std::cout << "Listening for incoming connections.." << std::endl;
			listen(sockfd,5);
			clilen = sizeof(cli_addr);
			newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
			std::cout << "Incoming connection!" << std::endl;
			if (newsockfd < 0) std::cout <<("ERROR on accept");
			else std::cout << n << " Accepting TCP connection" << std::endl;
			n=1;
			while(n>=0){
				try{
					bzero(buffer,256);
					n = read(newsockfd,buffer,255);
					if (n < 0) std::cout <<("ERROR reading from socket");
					if	(n==0) throw 0;
					std::cout << n << " Here is the message:" << buffer << std::endl;
					//n = write(newsockfd,"hello",18);
					//if (n < 0) std::cout <<("ERROR writing to socket");
					std::cout << "Processing input\n";
					for(char ch : buffer){
						if(ch=='A') threads.push_back(new ithread(&User::requestPayment, u, 100, r));
						else if(ch=='B') threads.push_back(new ithread(&User::requestWithdraw, u, 100));
						else {
							listenflag=-2;
							break;
						}
					}


				}catch(int error){
					n=-1;
				}

			}
		}

	#endif
	
	while(SUBMISSION_WEEK< MULTITHREAD_WEEK){
		std::cin >> ch;
		if(ch=='A') u->requestPayment(100, r);
		if(ch=='B') u->requestWithdraw(100);
	}
	while(SUBMISSION_WEEK>= MULTITHREAD_WEEK){
		std::cin >> ch;
		if(ch=='A') threads.push_back(new ithread(&User::requestPayment, u, 100, r));
		if(ch=='B') threads.push_back(new ithread(&User::requestWithdraw, u, 100));
	}
} 


int main(int argc, char *argv[]) {
	std::cout << "Submission version: "<< SUBMISSION_WEEK << std::endl;
	//Construct and allocate users along with bank accounts
	u = new User("ata", new BankAccount(100000,u));
	r = new User("receivertest", new BankAccount(100,r));

	handleInput(u);//doesn't terminate because of the io loop
	return 0;
}