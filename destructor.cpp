#include<iostream>
using namespace std;

class Par{
    public:
    Par(){
        cout<<"Par Constructor\n";
    }
    virtual ~Par(){
        cout<<"Par Destructor\n";
    };
     void print(){
        cout<<"Par print\n";
    }
};

class Child:public Par{
    public:
    void print(){
        cout<<"Child print\n";
    }
    public:
    Child(){
        cout<<"Child Constructor\n";
    }
     ~Child(){
        cout<<"Child Destructor\n";
    };
};

int main(){
    Par *p = new Child();
    p->print();
     //Child *c = new Child();
     //c->print();
     delete p;
     //delete c;
}