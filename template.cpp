#include<iostream>
using namespace std;

template <typename t>
void print( t &x)
{
    cout<<x++<<endl;
}

int main()
{
    int i=10;
    char s='a';
    print<int>(i);
    print<int>(i);
    print<char>(s);
    print<char>(s);
}