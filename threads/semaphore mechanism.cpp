#if 1

#include<iostream>
#include<stack>
#include <queue>
#include <thread>
#include <vector>
#include <unistd.h>
#include <semaphore>
#include <thread>
using namespace std;

pthread_t t[3];
queue<int> q;
pthread_mutex_t lk;
int slp = 3;
enum sem_flag{
	hold,
	proceed
};
enum sem_flag sign;

std::binary_semaphore sem;

void* print(){

	while(!q.empty()){
		cout<<q.front()<<", ";
		q.pop();
	}
}

void* odd(void *){
	
    for(int i=1; i<10; i=i+2)
	{
		#if 0
		//posix semaphore
		while(sign==hold);
		sign = hold;
		#endif
		//pthread_mutex_lock(&lk);

		sem.acquire();

		q.push(i);

		sem.release();
		//pthread_mutex_unlock(&lk);
		#if 0
		//posix semaphore
		sign = proceed;
		#endif
		sleep(slp);
	}
}

void* even(void *){

    for(int i=2; i<10; i=i+2)
	{
		#if 0
		//posix semaphore
		while(sign==hold);
		sign = hold;
		#endif
		//pthread_mutex_lock(&lk);

		sem.acquire();

		q.push(i);
		
		//pthread_mutex_unlock(&lk);

		sem.release();

		#if 0
		//posix semaphore
		sign = proceed;
		#endif
		sleep(slp);
	}
}

int main(){
    vector<int> v;
	
	pthread_mutex_init(&lk, NULL);

	sign = proceed;
#if 0
//posix thread
	pthread_create(&t[0], NULL, &odd, NULL);
	pthread_create(&t[1], NULL, &even, NULL);
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
#endif

#if 1
//C++ thread
    thread t1(odd), t2(even);
    t1.join();
    t2.join();
#endif
	print();
    cout<<"Shreyas\n";
	pthread_mutex_destroy(&lk);
}
#endif

