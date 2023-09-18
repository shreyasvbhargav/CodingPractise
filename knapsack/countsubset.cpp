/*given an arr, count number of subsets for a given sum
arr = {2,3,5,6,8,10}
sum = 10
subsets : {2,3,5}, {2,8}, {10}
output = 3
*/

#include<iostream>
#include<stack>
#include <queue>
#include <thread>
#include <vector>
#include <unistd.h>
#include <semaphore>
#include <thread>
using namespace std;


//int arr[] = {1,2,2,3,4,5};
int arr[] = {2,3,5,6,8,10};
int **dp;

int countSubset(int arr[], int size, int sum){
    if(sum==0)
        return 1;
    else if(size==0)
        return 0;

    if(arr[size-1]>sum)
        return countSubset(arr, size-1, sum);
    else
        return (countSubset(arr, size-1, sum-arr[size-1]) + countSubset(arr, size-1, sum));
}

int countSubset_dp(int arr[], int size, int sum){
    int i=0, j=0;
    // if(sum==0)
    //     dp[sum-1][size-1] = 1;
    // else if(asize==0)
    //     dp[sum-1][size-1] = 0;
    for(i=1; i<size+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] > sum)
                dp[i][j] = dp[i-1][j]; 
            else
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j]; //(countSubset(arr, asize-1, sum-arr[asize-1]) + countSubset(arr, asize-1, sum));
        }
    }
}

int main(){ 
    int sum=10;
    int i=0;
    int asize = sizeof(arr)/sizeof(arr[0]);

    cout<<countSubset(arr, asize, sum)<<endl;

    //dp
    dp = (int **)malloc((asize+1)*sizeof(int *));
    for(i=0; i<asize+1; i++)
        dp[i] = (int *)malloc((sum+1)*sizeof(int));

    //memset(dp, -1, sizeof(dp));
    for(i=0; i<sum+1; i++)
        dp[0][i] = 0;
    for(i=0; i<asize+1; i++)
        dp[i][0] = 1;

    countSubset_dp(arr, asize, sum);
    cout<<dp[asize][sum]<<endl;
}