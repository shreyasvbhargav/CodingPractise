#include <iostream>
using namespace std;

//class members are private by default
//public members can be accessed from anywhere by reference through class object
//private & protected members can only be access by class members and class functions or by friend functions and friend classes
//only diff between protect & private is protected members can be access by member functions of inherited class
//if the inherited child class has a member with same name as member of parent class, the member of child class will be used by default unless specified

class Parent {
    int check;
    private:
        int priv;
    protected:
        int protect;
    public:
        int pub;
        void print(int x, int y);
};

class Child:public Parent {
    public:
        Child(int x){
            protect = x;
        }
        void see()
        {
            cout<<pub<<endl;
            cout<<protect<<endl;
        }
};

class Ch2:public Child{
    public:
        void see(){
            cout<<pub<<endl;
        }
};

void Parent::print(int x, int y)
{
   protect=x;
    priv = y;
   cout<<protect<<endl;
    cout<<priv<<endl;
}

int main(){
    Parent p;
    p.pub=10;
    cout<<p.pub<<endl;
    Child c(69);
    c.pub = 6;
    c.see();
        p.print(20,30);

}