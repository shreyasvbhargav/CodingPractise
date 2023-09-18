#include<iostream>
#include <string>
using namespace std;

string reverse(string s){
    int i=0, j=s.length()-1;
    char t;

    while(i<j){
        t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }

    return s;
}

int main(){
    string s = "shreyas";
    cout<<reverse(s)<<endl;
}