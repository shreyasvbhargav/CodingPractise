//given an arr, print top k frequent numbers

#include <iostream>
#include <queue>
#include <map>
using namespace std;

void findFrequentK(int arr[], int k, int arr_size){
    int i;
    map<int, int> m;
    map<int, int>::iterator it;
    priority_queue<pair<int, int> > q;

    for(i=0; i<arr_size; i++){
        it = m.find(arr[i]);
        if(it == m.end())
            m[arr[i]] = 1;
        else
            m[arr[i]]++;
    }

    for(it=m.begin(); it!=m.end(); it++){
        q.push(make_pair(it->second, it->first));
    }

    while(k--)
    {
        cout<<q.top().second<<" "<<q.top().first<<endl;
        q.pop();
    }
}

int main(){
    int k =2;
    int arr[] = {1,1,1,1,2,2,3,4,2,4};
    findFrequentK(arr, k, sizeof(arr)/sizeof(arr[0]));
}