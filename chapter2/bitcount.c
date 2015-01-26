/*count the number of 1 bits*/
#include<stdio.h>

int bitcount(int);

int main()
{
	int i;
	i = getchar() - '0';
	printf("%d\n",bitcount(i));
	return 0;
}

int bitcount(int x)
{
	int d;
	for(d = 0 ; x != 0 ; x >>= 1)
	{
		if(x & 01)
		{
			d++;
		}
	}
	return d;
}
