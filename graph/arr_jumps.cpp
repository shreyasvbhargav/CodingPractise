//given an array, find min jumps required to reach end of arr from the index-0
//you are allowed to jump only of arr[i]==arr[j] or to (i-1) or (i+1)
//{10, 2, 40, 10, 5, 5, 7, 40, 2} -> can jump from 10-10-40-40-2(4 jumps) or 10-2-2(2)

#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int findJumps(int arr[], int size){
    int count, index, pos, qsize;
    bool visit[size];
    queue<int> q;
    unordered_map <int, vector<int> > mp;
    
    memset(visit, false, size*sizeof(bool));
    //memset(count, INT_MAX, size*sizeof(int));

    for(int i=0; i<size; i++){
        mp[arr[i]].push_back(i);
    }

    q.push(0);
    visit[0] = true;

    while(!q.empty()){
        qsize = q.size();

        for(int i=0; i<qsize; i++){
            //(index + 1)
            index = q.front();
            q.pop();

            pos = index + 1;
            if(pos <= (size-1))
            {
                //count[pos] = min(count[pos], count[index]+1);
                
                if(pos == (size-1))
                    return count;

                if(!visit[pos])
                    q.push(pos);
                visit[pos] = true;
            }


            //(index - 1)
            pos = index - 1;
            if(pos > 0 && !visit[pos])
            {
                //count[pos] = min(count[pos], count[index]+1)
                q.push(pos);
                visit[pos] = true;
            }

            for(auto it : mp[arr[index]]){
                if(it == index)
                    continue;
                
                if(!visit[it]){
                    q.push(it);
                    visit[it] = true;
                }

                mp.erase(arr[index]);
                //count[it] = min(count[it], count[index]+1);
            }
        }
        count++;
    }
    return -1;
}

int main(){

    int arr[] = {10, 2, 40, 10, 5, 5, 7, 40, 2};
    //vector<int> arr = {10, 2, 40, 10, 5, 5, 7, 40, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<findJumps(arr, size)<<endl;
}