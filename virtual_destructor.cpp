#include<iostream>
using namespace std;
class Par{
     public:
        Par(){
            cout<<"constructing Par\n";
        }
        virtual ~Par(){
            cout<<"destructing Par\n";
        }
};
class Child:public Par{
     public:
        Child(){
            cout<<"constructing Child\n";
        }
        ~Child(){
            cout<<"destructing Child\n";
        }
};

int main(){
    Child *c = new Child;
    Par *p = c;
    delete p;
}