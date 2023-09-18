#include<iostream>
using namespace std;

class Par{
    public:
        int i;
        Par(){
            i=0;
        }
        void call(){
            print();
        }
        virtual void print(){
            cout<<"Par class"<<endl;
        }
};

class Der:public Par{
    public:
        void print(){
            cout<<"Der class"<<endl;
        }
};

int main()
{
    Par p;
    Der d;
    p.call();
    d.call();
}