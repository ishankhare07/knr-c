#include<stdio.h>
#define n 10

int binsearch(int,int[]);

int main()
{
	int x,v[n],i;
	for(i = 0 ; i < n ; i++)
	{
		v[i] = i;
	}
	x = getchar() - '0';
	printf("%d\n",binsearch(x,v));
	return 0;
}

int binsearch(int x, int a[])
{
	int low,mid,high;
	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(x == a[mid])
		{
			return mid;
		}
		else
		{
			if(x < a[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	return -1;
}
