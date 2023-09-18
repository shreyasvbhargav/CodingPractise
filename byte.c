#include <stdio.h>
int main()
{
	int a[4];
	int (*p)[4] = &a;
	printf("%0x, %d\n ", p, p);
	p++; 
	printf("%0x, %d\n ", p, p);
}
