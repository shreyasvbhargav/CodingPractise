#include<iostream>
using namespace std;

static int b;

int main(){
    int aa[] = {10, 110};
    int a = 5;
    int *const ptr = &a;
    int *p = aa;
    
    cout<<aa<<endl;
    cout<<(*p)++<<endl;
    cout<<*p<<endl;
    p++;
    cout<<*p<<endl;

    
    cout<<*ptr<<endl;
    (*ptr)++;
    //ptr = aa;

    cout<<*ptr<<endl;

    if(int i = 10){
        cout<<"YES\n";
    }
}
