/*given range of integers, print "Fizz" if int is divisible by 3, "Buzz" if divisible by 5, "FizzBuzz" if divisible by 3 & 5*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int i=0, n;

    string out = "";
    for(i=1; i<20; i++)
    {
        out = "";
        if((i%3)==0)
            out += "Fizz";
        if((i%5)==0)
            out += "Buzz";
        if((i%3) && (i%5))
            out += to_string(i);
        cout<<out<<" ";
    }
    cout<<endl;
}