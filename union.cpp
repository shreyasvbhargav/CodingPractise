#include<iostream>
using namespace std;

union test{
	int x;
	int y;
};

enum en{
	a,
	b
};

int main()
{
	test t;
	enum en val;
	val = a;
	t.x=val;
	cout<<t.x<<", "<<t.y<<endl;	
	t.y=10;
	cout<<t.x<<", "<<t.y<<endl;	
}
