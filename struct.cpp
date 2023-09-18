#include <iostream>
using namespace std;

struct abc{
    int a;
};

enum add{a,b,c};

typedef struct structc_tag {
    char c;
    char a;

    double d;
    structc_tag(){
        cout<<"inside structc_tag"<<endl;
    }
} structc_t;

int main(){
    structc_t s;
    cout<<sizeof(s)<<endl;
    add check = b;
    cout<<check<<endl;
}