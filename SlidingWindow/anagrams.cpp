/*
Given a string and a pattern, count number of occurrences of anagrams of pattern in the str
Eg:
str = aabaabaa
ptr = aaba
anagrams of ptr = aaba, abaa, baaa, aaab 
Soln:
anagram of ptr will have 3a's & 1b
so look for 3a-1b in sliding window of str
*/

#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

void countChar( char *p, int j, map<char, int> &cp){
    int i=0;
    char c;
    map<char, int>::iterator it;
    //auto i;
    for(i=0; i<=j; i++)
    {
        c = p[i];
        it = cp.find(c);
        if( it==cp.end() )
            cp.insert(make_pair(c, 1));//cp.insert(pair<char, int>{ c, 1 }); 
        else
            it->second++;
    }
}

int countAnagrams(string str, string ptr){
    int window = ptr.length()-1;
    int size = str.length();
    int i, j;
    int count=0;
    map<char, int> cp, tmp;

    countChar((char *)ptr.c_str(), ptr.length()-1, cp);

    for(i=0, j=i+1; j<size; i++, j++){
        while((j-i) < window)
            j++;
        
        countChar((char *)str.c_str()+i, window, tmp);
        if(tmp == cp)
            count++;
        tmp.clear();
    }
    return count;
}

int main(){
    string str, ptr;
    cout<<"Enter string\n";
    //str = "aabaabaa";
    cin>>str;
    cout<<"Enter pattern\n";
    //ptr = "aaba";
    cin>>ptr;

    cout<<countAnagrams(str, ptr)<<endl;
}
