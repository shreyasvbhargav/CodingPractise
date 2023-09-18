#include<iostream>
#include <vector>
#include <thread>
using namespace std;

void printS(){
    int i=5;
    while(i--)
    cout<<"Shreyas\n";
}

void printM(){
    int i=5;
    while(i--)
    cout<<"Manasa\n";
}

int main(){
    // int arr[] = {5,7,2,3,9,10,4};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int i=0;

    // for(i = 0; i<size; i++)
    //     cout<<arr[i]<<", ";
    // cout<<endl;
    // sort(arr, arr+size);

    // for(i = 0; i<size; i++)
    //     cout<<arr[i]<<", ";
    // cout<<endl;
    
    vector<thread> v;
    v.emplace_back(printS);
    v.emplace_back(printM);
}
