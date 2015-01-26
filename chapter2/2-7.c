#include<stdio.h>

int invert(int,int,int);

int main()
{
	int x,p,n;
	x = 100;
	p = 5;
	n = 3;
	printf("%d\n",invert(x,p,n));
	return 0;
}

int invert(int x, int p, int n)
{
	return (~((x >> (p+1-n)) & ~(~0 << n)));
}
