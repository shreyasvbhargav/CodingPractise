#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include<stack>
#include<queue>
#include<vector>
#include<list>
using namespace std;
/*
class Str{
	public:
	
		vector<char> s;

		Str(char *ptr){
			for(int i=0; i<strlen(ptr); i++)
				s.push_back(ptr[i]);
		}
		
		void reverse(){
			//vector<char> rev
			int size = s.size();
			for(int i=0; i<size; i++)
			{
				char tmp = s[i];
				s[i] = s[size-1];
				s[size-1] = tmp;
				size --;
			}
		}
};
*/
int diff(int a, int b)
{
    if(a>b)
        return (a-b);
    else
        return (b-a);
}


int find_max_apples(int max_size_difference, vector<int> apple_sizes) {
    int i=0, j=0;
    int max=0, count=0, res=0;
 
    for(i=0, j=i+1; j<apple_sizes.size(); j++,i++)
    {
        res = diff(apple_sizes[i], apple_sizes[j]);
        if(res<=max_size_difference){
            count++;
            //cout<<count<<endl;
        }
        else{
            if(max<count)
                max = count;
            //cout<<"set count 0\n";
            count=0;
        }
    }
    if(max<count)
                max = count;
    return max;
}

int main()
{
	//Str *obj = new Str("cisco");
	//vector<char> rev;
	
	// cout<<obj->s.data()<<endl;


	// obj->reverse();
	// cout<<obj->s.data()<<endl;
	/*
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(1);
	vec.push_back(11);
	vec.push_back(2);
	vec.push_back(17);
	vec.push_back(3);
	vec.push_back(19);
	vec.push_back(4);
	vec.push_back(34);
	vec.push_back(5);
	vec.push_back(6);
	cout<<find_max_apples(5, vec)<<endl;
	*/

	unsigned int a = 8147529492;
	cout<<a<<endl;

	
}


