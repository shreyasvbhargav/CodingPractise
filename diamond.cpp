#include<iostream>
using namespace std;

#if 1
class Person{
    public:
    int a;
    Person(){
        cout<<"Person\n";
    }
    void show(){
        cout<<"This is Person show\n";
    }
};

class Employee: virtual public Person{
    public:
    Employee(){
    cout<<"Employee\n";
    }
};

class Employer:virtual public Person{
    public:
     Employer(){
    cout<<"Employer\n";
     }
     void say_yaay(){
        cout<<"Employer yaay\n";
     }
};

class Shreyas:public Employee, public Employer{
    public:
     Shreyas(){
    cout<<"Shreyas\n";
     }
     void say_yes(){
        cout<<"Shreyas says yes\n";
     }
};

int main(){
    Shreyas s, *so;
    Employer e;

    //s.show();
    so = (Shreyas *)&e;
    so->say_yes();
    // Person p;
    // p.a = 10;
    // s.a = 100;

    // cout<<s.a<<", "<<p.a<<endl;
}
#endif
