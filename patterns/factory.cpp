#include <iostream>
using namespace std;
 
enum type{
    samsung,
    nokia,
    apple
};
// Library classes

class Smartphone{
    public:
        Smartphone(){}

};

class Samsung:public Smartphone{
    public:
        Samsung(){
            cout<<"Samsung\n";
        }
};

class Nokia:public Smartphone{
    public:
        Nokia(){
            cout<<"Nokia\n";
        }
};

class SmartphoneFactory
{
    public:
    Smartphone * newPh(type t){
        switch(t){
            case samsung:
                return new Samsung();
            case nokia:
                return new Nokia();
            case apple:
                return NULL;
               //return new Nokia();
            default:
                return NULL;
        }
    }
    ~SmartphoneFactory(){
        cout<<"Deleting\n";
    }
};

class Create{
    public:
    Create(){  
    }
    Smartphone* buildPh(type t){
        SmartphoneFactory *s = new SmartphoneFactory();
        ph = s->newPh(t);
        delete s;
        return ph;
    }
    private:
        Smartphone *ph;
};

int main(){
    Create *c = new Create();
    Smartphone *s = c->buildPh(samsung);
    Smartphone *n = c->buildPh(nokia);
}