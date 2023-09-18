#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string line;
    fstream fout;
    fout.open("test.txt", ios::out);

    while(fout){
        getline(cin, line);
        if(line == "0")
            break;

        fout<<line<<endl;
    }
    fout.close();

    fstream fin;
    fin.open("test.txt", ios::in);
    //fin.open("test.txt");
    //getline(fin, line);
    while(getline(fin, line)){
        cout<<line<<endl;
    }
    fin.close();
}