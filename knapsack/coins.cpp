/*
Given unlimited set of coins, find number of ways to reach max sum
coins[] = {1,2,3}
sum = 5
ways : {1,1,1,1,1}, {2,3}, {1,1,1,2}, {1,1,3}, {1,2,2} = 5
Unbounded knapsack
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


int countWays(int coins[], int size, int sum){
    if(sum == 0)
        return 1;
    else if(size == 0)
        return 0;

    if(sum < coins[size-1])
        return countWays(coins, size-1, sum);
    else
        return (countWays(coins, size, sum-coins[size-1]) + countWays(coins, size-1, sum));
}

int countWaysDp(int coins[], int size, int sum, int (*dp)[4]){
    int i=0, j=0;

    for(i=0; i<sum+1; i++)
        dp[0][i] = 0;
    for(i=0; i<size+1; i++)
        dp[i][0] = 1;

    for(i=1; i<size+1; i++){
        for(j=1; j<sum+1; j++){
            if(coins[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
        }
    }
    
    for(i=0; i<size+1; i++){
        for(j=0; j<sum+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return dp[size][sum];
}

int main(){
    int coins[] = {1,2};
    int size = sizeof(coins)/sizeof(coins[0]);
    int sum = 3;
    // int **dp = (int **)malloc(sizeof(int *)*(size+1));
    // for(int i=0; i<(size+1); i++)
    //     dp[i] = (int *)malloc(sizeof(int) * (sum+1));
    int dp[3][4];

    memset(dp, 0, sizeof(dp));

    //cout<<countWays(coins, size, sum)<<endl;
    cout<<countWaysDp(coins, size, sum, dp)<<endl;
}