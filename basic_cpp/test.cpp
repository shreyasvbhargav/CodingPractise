// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <condition_variable>

using namespace std;
#if 0

int checkSum(int arr[], int size, int sum){

    if(sum == 0)
        return 1;
    if(size == 0)
        return -1;

    if(arr[size-1] > sum)
        return checkSum(arr, size-1, sum);
    else
        return max(checkSum(arr, size-1, sum-arr[size-1]), checkSum(arr, size-1, sum));
}


int main() {
    // Write C++ code here
    int arr[] = {2, 5, 4 ,6, 8};
    int key = 119;
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<checkSum(arr, size, key);
    
    return 0;
}
#endif
//1. {2,5,4,6}, size = 4, sum = 2
//2. {2,5,4,6}, size = 4, sum = 10

class employee{
    //int id=10;
    public:
    int id;
    employee(){
        cout<<id;
    }
};

typedef struct cell{
    int x;
    cell(int a):x(a){}
    cell(){}
}cell;

int main(){
  //employee e;

    queue<cell *> q;
    cell *tmp;

    for(int i =1; i<=5; i++)
        q.push(new cell(i));

    for(int i=0; i<5; i++){
        tmp = q.front();
        q.pop();
        cout<<"Printing: ";
        cout<<tmp->x<<endl;;
    }
  
}