#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

int findDuplicate(vector<int>& nums) {
        int i;
        set<int>::iterator it;
        set<int> s;
    
        for(i=0; i<nums.size(); i++){
            it=s.find(nums[i]);
            if(it==s.end())
                s.insert(nums[i]);
            else
                return nums[i];
        }
    return -1;
}

int main(){
    vector<int> s;
    vector<int>::iterator it;
    string s;
    if(s.empty)
    s.push_back(4);
    s.push_back(2);
    s.push_back(10);
    s.push_back(6);
    s.push_back(10);
    s.push_back(8);

    for(it=s.begin(); it!=s.end(); it++)
        cout<<*it<<endl;
    cout<<endl;

    cout<<"Dup : "<<findDuplicate(s)<<endl;

    // set<int>::iterator res = s.begin();
    // res = s.find(6);
    //cout<<*res<<endl;

}