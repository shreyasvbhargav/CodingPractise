#include <iostream>
#include <string>
#include <vector>
using namespace std;

class String{
    public:
        char name[10];
        String(){
            cout<<"Constructor\n";
            strcpy(name, "Shreyas");
        }
        String( char *s ){
            cout<<"Param Constructor\n";
        }
        String(String &o){
            cout<<"Copy Constructor\n";
            strcpy(this->name, o.name);
        }
        String(String&& m){
            cout<<"Move Constructor\n";
            strcpy(this->name, m.name);
            memset(m.name, '\0', sizeof(m.name));
        }
};

int main(){
    char tmp[] = "tmp";
    String s1;
    String s2(s1);
    cout<<s2.name<<endl;
    String s33 = move(s1) ;
    cout<<s33.name<<endl;
    cout<<s1.name<<endl;
}