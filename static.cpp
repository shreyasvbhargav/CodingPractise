#include <iostream>
using namespace std;

void test(){
	cout<<"test\n";
}

class sam {
	public:
		static int val;
		static void fun();
		void print();
};


int sam::val = 1;

void sam::fun(){
	cout<<"Func\n";
	sam s;
	s.print();
}

void sam::print(){
	cout<<"print: "<<sam::val++<<"\n";
}

int main(){
	sam::fun();
	sam s;
	s.print();
	s.print();
}
