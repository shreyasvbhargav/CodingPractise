//could not understand this concept!

#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(){
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(15);
    v.push_back(7);
    v.push_back(3);
    v.push_back(13);
    v.push_back(18);

    array<int, 10> arr;
    arr[0] = 10;
    cout<<arr.size()<<", "<<arr[200]<<endl;

    //10 20 15 7 23 13 18
    // for(int i=0; i<v.size(); i++)
    //     cout<<v[i]<<", ";
    // cout<<endl;

    // vector<int>::iterator low1, low2, low3;
    // low1 = lower_bound(v.begin(), v.end(), 10);
    // low2 = upper_bound(v.begin(), v.end(), 10);

    // cout<<*low1<<", "<<*low2<<endl;
    // low1--;
    // cout<<*low1<<endl;
}