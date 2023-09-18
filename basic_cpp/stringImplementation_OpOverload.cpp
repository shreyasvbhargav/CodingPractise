#include <iostream>
using namespace std;

//Implementing a string class
//included implementation of copy constructor, operator overloading

class String{
    public:
        char *str;
        String(){

        }
        String(const char *tmp){
            cout<<"Param const\n";
            str = (char *)malloc(strlen(tmp));
            strcpy(str, tmp);
        }
        void operator =(char *obj){
            cout<<"Operator overld : "<<obj<<endl;
            str = (char *)malloc(strlen(obj));
            strcpy(str, obj);
            
        }
        String(String &obj){
            cout<<"Copy cons\n";
            this->str = obj.str;
        }

        int length(){
            return strlen(this->str);
        }
};

int main(){
    String tmp("Bhargav");
    String s;
    s = tmp.str;
    s = "Shreyas";
    String a = s;
    cout<<s.str<<endl;
}