#include<iostream>
#include <set>
using namespace std;

std::mutex g_num_mutex;
std::unique_lock<mutex> lk(g_num_mutex);
int main(){

    set<int> s;
    set<int>::iterator i;

g_num_mutex.lock();
lk.lock();
    s.insert(5);
    s.insert(2);
    s.insert(6);
    s.insert(1);
    s.insert(4);
lk.unlock();
g_num_mutex.unlock();
    for(i=s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
  
}