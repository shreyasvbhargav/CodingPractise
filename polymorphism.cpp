#include<iostream>
using namespace std;

class Base{
    public:
     double add(double a, double b)
    {
        cout<<"int\n";
        return a+b;
    }
};

class Der:public Base{
    public:
    double add(double a, double b)
    {
        cout<<"double\n";
        return a+b;
    }
};

int main()
{
    int a=1, b=2;
    double c=2.1, d=3.2;
    Base p;
    Base *base;// = &p;
    Der der;
    cout<<base->add(a,b)<<endl;
    //base = &der;
    cout<<base->add(c,d)<<endl;
}