#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;


int toNum(char c)
{
    return (c-'0');
}

int fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}

int main()
{
    string str;
    int i,j, pos =0 ;
    cout<<"Enter str\n";
    cin>>str;
#if 0
    cout << "Finding substr's:\n";
    int n = strlen(str.c_str());
    cout<<"Len : "<<n<<endl;
    for(i=0; i<n-1; i++)
    {
        for(j=1; j<=n; j++)
            cout<<str.substr(i,j)<<endl;
    }
#endif

//sum of substrings where string represents a number
#if 0
    int n = str.size();
    char num[n];
    int sum=0;

    int rs = fact(n);
    int res[rs];

    for(i=0; i<n; i++) {
	   num[i] = toNum(str[i]);
	}

    for(i=0; i<n; i++)
    {
        sum = 0;
        for(j=i; j<n ;j++){
            sum = sum + num[j];
            res[pos++] = sum;
        }
        cout<<endl;
    }

    for(i=0; i<pos; i++)
        cout<<res[i]<<", ";
    cout<<endl;
#endif

    int n = str.length();
 
    // allocate memory equal to length of string
    int sumofdigit[n];
 
    // initialize first value with first digit
    sumofdigit[0] = toNum(str[0]);
    int res = sumofdigit[0];
 
    // loop over all digits of string
    for (int i = 1; i < n; i++) {
        int numi = toNum(str[i]);
 
        // update each sumofdigit from previous value
        sumofdigit[i] = (i + 1) * numi + 10 * sumofdigit[i - 1];
 
        // add current value to the result
        res += sumofdigit[i];
    }
    cout<<res<<endl;
}
