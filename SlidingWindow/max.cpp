#include<iostream>
#include<stack>
#include <queue>
#include <vector>
using namespace std;

void slidemax(int *v, int size, int k){
    deque<int> max;
    int i;

    max.push_back(v[0]);
    for(i=1; i<k; i++){
        while(!max.empty() && v[i]>max.back())
            max.pop_back();
        max.push_back(v[i]);
    }

    cout<<max.front()<<", ";

    for(i=k; i<size; i++){
        if(v[i-k] == max.front())
            max.pop_front();

        while(!max.empty() && v[i]>max.back())
            max.pop_back();
        max.push_back(v[i]);
        
        cout<<max.front()<<", ";   
    }
}

void brute(int *v, int i, int k){
    int max = v[i];
    for(int c=i+1; c<i+k; c++)
        if(max<v[c])
            max = v[c];
    cout<<max<<", ";
}

int main(){

    int v[] = {1, 3, -1, -3, -4, 3, 6, 7};
    //3 3 
    int n = sizeof(v)/ sizeof(v[0]);
    int k = 3;
    cout<<"Slide:\n";
    slidemax(v, n, k);
    cout<<"\n\nBrute : \n";
    for(int i=0; i<=n-k; i++)
        brute(v, i, k);

}
//3 3 5 5 6 7