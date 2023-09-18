#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
#include <thread>
using namespace std;
#define MAX 20
//volatile int cnt=1;

std::mutex mu;
std::condition_variable cond;
int cnt = 1;

void odd()
{
    while(cnt<MAX)
    {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker,[](){ return (cnt%2 == 1); });
    cout<< "From Odd:    " <<  cnt << endl;
    cnt++;
    locker.unlock();
    cond.notify_all();
    }

}

void even()
{
    while(cnt<MAX)
    {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker,[](){return (cnt%2 == 0);});
    cout<< "From Even: " << cnt << endl;
    cnt++;
    locker.unlock();
    cond.notify_all();
    }
}


int main(){
    thread t1(odd), t2(even);
    t1.join();
    t2.join();
}