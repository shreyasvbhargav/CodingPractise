//given an arr, find 2 values such that their sum is eq to target
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;


bool findSum(vector<int> arr, int size, int tar){
    bool lh, rh;

    if(tar == 0)
        return true;
    else if(size == 0)
        return false;

    lh = findSum(arr, size-1, tar);
    rh = findSum(arr, size-1, tar-arr[size-1]);
    if(rh)
        cout<<arr[size-1]<<" ";
    
    return lh||rh;
}

int main(){
    vector<int> arr={2,7,11,15};
    int target = 9;

    findSum(arr, arr.size(), target);
}