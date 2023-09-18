#include <iostream>
using namespace std;

int add(int a, int b){
    return (a+b);
}

double add(double a, double b){
    return (a+b);
}

int main(){
    int a=10, b=5;
    double c=2, d=8;
    cout<<add(a,b)<<endl;

    cout<<add(d, c)<<endl;
}