//given an array of numbers, print sum between k1st and k2nd smallest numbers
// arr[] = {1, 2, 3, 4, 5, 6}, k1 = 3, k2 = 6. sum between 3rd & 6th smallest elem : 4+5 = 9

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k1 = 2, k2 = 7;
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum=0;

    priority_queue<int> maxh;

    for(int i=0; i<size; i++){
        maxh.push(arr[i]);
    }

    if(maxh.size() >= k2){
        while(maxh.size() > k2)
            maxh.pop();

        maxh.pop();
        while(maxh.size() > k1){
            sum += maxh.top();
            maxh.pop();
        }      
    }
    cout<<sum;
}