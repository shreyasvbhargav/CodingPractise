//given an arr, find arr[i] arr[j] arr[k] such that i!=j!=k and their sum is 0
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;


void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    cout<<endl;
}

bool findSum(vector<int> nums, int size, int k, int sum){
    bool lh, rh;
    if(k==0 && sum==0){
        return true;
    }
    else if(k == 0 || size == 0){
        return false;
    }
    lh = findSum(nums, size-1, k, sum);
    rh = findSum(nums, size-1, k-1, sum+nums[size-1]);
    if(rh)
        cout<<nums[size-1]<<" ";
    return lh||rh;
}

void find(vector<int> nums, int size, int k, int sum){
    queue<int> q;
    findSum( nums, size, k,  sum);
}
int main(){
    vector<int> nums = {-1,0,1, 2, -1, -4};
    int k = 3;
    int sum = 0;

    find(nums, nums.size(), k, sum);
}