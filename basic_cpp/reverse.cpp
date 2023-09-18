#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str = " gniyalp";
    int i=0;
    int len = str.length();
    stack<char> st;

    for(i =0; i<len; i++)
    {
        while(str[i] != ' ' && i<len){
            st.push(str[i]);
            i++;
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }

        cout<<" ";
    }
}