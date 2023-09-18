//given an array, find min jumps req to reach end of arr.
//elem in the arr indicate max jump one can take
//arr[] = {1,3,5,8,9,2,6,7,6,8,9} -> min jumps : 1->3->9->9 or 1->3->8->9

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;


int findJumps(vector<int> &arr){
    int jumps = 1;
    int size = arr.size();
    int maxReachable=arr[0];
    int step = arr[0];

    if(size <= 1 || arr[0] == 0)
        return 0;
    if(arr[0] >= size)
        return jumps;

    for(int i = 1; i<size; i++)
    {
        if( i == (size-1) )
            return jumps;
        if(arr[i] >= (size-1)-i )
            return jumps+1;

        // if(maxReachable >= (size-1)-i)
        //     return jumps+1;
        
        maxReachable = max(maxReachable, i+arr[i]);

        step--;

        if(step == 0){
            jumps++;
            if (i >= maxReachable)
                return -1;
            step = maxReachable - i;
        }
    }
    return jumps;
}

int main(){
    vector<int> arr = {1,0,5,2,6,7,6,8,9};
    cout<< findJumps(arr);
}