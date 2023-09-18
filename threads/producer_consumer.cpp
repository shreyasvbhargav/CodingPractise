#include <stdio.h>
#include<iostream>
#include <queue>
#include <thread>
#include <unistd.h>
//#include <semaphore>
#ifdef __APPLE__
#include <dispatch/dispatch.h>
#else
#include <semaphore.h>
#endif
#include <mutex>
using namespace std;

//queue<int> dataq;
int dataq[5];
int index1 = 0;
pthread_mutex_t mut;
#ifdef __APPLE__
    dispatch_semaphore_t    semEven, semOdd, semFull, sem;
#else
    sem_t semEven, semOdd;
#endif

std::mutex mtx;

#if 0
void producer_even(){
    for(int i=2; i<=10; i=i+2){
        //sem_wait(sem);
        //lock_guard<mutex> lock(mtx);
        dispatch_semaphore_wait(semEven, 0);
        dataq.push(i);
        dispatch_semaphore_signal(semOdd);
        //sem_post(sem);
        //sleep(1);
    }
}

void producer_odd(){
    
    for(int i=1; i<=10; i=i+2){
        //sem_wait(sem);
        //lock_guard<mutex> lock(mtx);
        dispatch_semaphore_wait(semOdd, 0);
        dataq.push(i);
        dispatch_semaphore_signal(semFull);
        //dispatch_semaphore_signal(semEven);
        //sem_post(sem);
        //sleep(1);
    }
}
#endif

void producer(){
    cout<<"Producer\n";
    for(int i=1; i<=40; ){

        dispatch_semaphore_wait(sem, 0);
        pthread_mutex_lock(&mut);

        while(index1 < 5){
            cout<<"Adding "<<i<<endl;
            dataq[index1++] = i++;
        }

        pthread_mutex_unlock(&mut);
        dispatch_semaphore_signal(sem);
        sleep(1);
        index1 = index1%5;
    }
    dispatch_semaphore_signal(sem);
}

void consumer(){
    int i;

    cout<<"Consumer\n";

    while(1)
    {
        dispatch_semaphore_wait(sem, 0);
        pthread_mutex_lock(&mut);

        for(i = 0; i<5; i++){
            cout<<"Removing "<<dataq[i]<<endl;
        }

        pthread_mutex_unlock(&mut);
        dispatch_semaphore_signal(sem);
        cout<<endl;
        
        if(dataq[i-1] == 40)
            break;

        sleep(1);
    }
    cout<<"Exiting consumer "<<endl;
}

int main(){

    //sleep(5);
    pthread_mutex_init(&mut, NULL);
    semEven = dispatch_semaphore_create(0);
    semOdd = dispatch_semaphore_create(1);
    //semFull = dispatch_semaphore_create(0);
    sem = dispatch_semaphore_create(1);
    //sem_init(&semEven, 0, 1);
    //sem_init(&semOdd, 0, 1);

    thread t1(producer);
    thread t2(consumer);
    //thread t2(producer_even);

    t1.join();
    t2.join();
    //consumer();
    dispatch_release(sem);
    //dispatch_release(semFull);
    pthread_mutex_destroy(&mut);
}