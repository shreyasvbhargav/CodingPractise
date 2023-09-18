#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int findMin(int *num, int n, int sum){
    if(sum == 0) 
        return 0;
    if( n == 0 )
        return 100;
    
    return min(1+findMin(num, n-1, sum-num[n-1]), findMin(num, n-1, sum));
}

int findMax(int *num, int n, int sum){
    if(sum == 0 || n == 0) 
        return 0;
    
    return max(1+findMax(num, n-1, sum-num[n-1]), findMax(num, n-1, sum));
}

int main(){
    int sum;
    int n;
    int i, tmp;
    int * num;

    cout<<"Enter target sum\n";
    cin>>sum;
    cout<<"enter num of elem in arr\n";
    cin>>n;

    num = (int *)malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        cin>>num[i];
        //cin>>tmp;
        //num.push_back(tmp);
    }

    cout<<"Max : "<<findMax(num, n, sum)<<endl;
    cout<<"Min : "<<findMin(num, n, sum)<<endl;
}