#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

//strtok will maintain internal static state to know where to continue tokenisation. passing NULL in subsequent call indicates to continue from prev state.

int main()
{
    char str[] = "Shreyas will do it";
    char str2[] = "Need to get excellent job";
    char *s = strtok(str," ");
    while(s != NULL){
        cout<<s<<endl;
        s = strtok(NULL, " "); 
        //s = strtok(str2, " "); // prog crash and out stuck at "Need" since tok will not continue
    }
}

#if 0

int main()
{
	char str[] = "Shreyas will do it";
	stringstream inp(str);
	string ptr;

	while(getline(inp, ptr, ' '))
		cout<<ptr<<endl;
}
#endif
