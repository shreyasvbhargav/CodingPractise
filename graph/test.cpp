#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

void check(int val[5]){
    for(int i=1; i<=5; i++)
        val[i-1] = i;
}

int main(){

    priority_queue<int> q;
    q.push(10);
    q.push(40);
    q.push(20);
    q.push(60);
    q.push(30);

    for(int i=0; i<q.size(); i++){
        cout<<q.top()<<endl;
        q.pop();
    }

    
}