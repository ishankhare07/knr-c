#include<stdio.h>

int power(int, int);

int main()
{
	int i;
	for(i = 0 ; i < 10 ; ++i)
	{
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	}
	return 0;
}

int power(int base, int n)
{
	int i,j=1;
	for(i = 0 ; i < n ; ++i)
	{
		j = j * base;
	}
	return j;
}
