#include<iostream>
using namespace std;

int a;

int main(){
	const char *str = "Shreyas";
	char ptr[] = "Will get better job";
	string s = "50LPA";

	char c='a';
	
	char* const p=&c;
	cout<<*p<<endl;
	
	*p = 'b';
	cout<<*p<<endl;

	// cout<<(str)<<endl;
	// str = "Bhargav";
	// cout<<(str)<<endl;
	// str++;
	// cout<<(str)<<endl;

	// cout<<ptr<<endl;
	// ptr[8] = 'a';
	// cout<<ptr<<endl;
	// cout<<s<<endl;
	// s = s + " CTC";
	// cout<<s<<endl;
}
