#include<iostream>
#include <vector>
#include <deque>
#include <forward_list>
#include <priority_queue>
using namespace std;

int add(int n){
    int sum = 0;
    
    if(n==0)
        return 0;

    sum += (n%10) + add(n/10);

    return sum;
}

void heapf(){
    priority_queue<int> h;
    h. 
}


int main(){
    // int n = 83;
    // cout<<add(83)<<endl;
    forward_list<int> f;

    f.assign(5,10);
    for(forward_list<int>::iterator it = f.begin(); it!=f.end(); it++)
        cout<<*it;
    cout<<endl;

    f.unique();
    for(forward_list<int>::iterator it = f.begin(); it!=f.end(); it++)
        cout<<*it;
    cout<<endl;
}
