// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <thread>
#include <condition_variable>
//#include <bits/stdc++.h>
using namespace std;

condition_variable cv;
mutex mtx;
bool dataReady = false;

void test1(){
     unique_lock<mutex> lk(mtx);
     //lk.lock();
    for(int i = 1;i <=5; i=i+1)
        cout<<i<<" ";
    lk.unlock();
    cv.notify_one();
    dataReady = true;
    //cv.notify_one();
}
void test2(){
    
    unique_lock<mutex> lk(mtx);
    cv.wait(lk);
    //lk.lock();
    for(int i = 6;i <=10; i=i+1)
        cout<<i<<" ";
    lk.unlock();

}

int main(){
  thread t1(test1);
  for(int i=0; i<10;i++);
  thread t2(test2);
  t1.join();
  t2.join();
}