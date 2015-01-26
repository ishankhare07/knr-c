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
	printf("%d",binsearch(x,v));
	return 0;
}

int binsearch(int x, int v[])
{
	int mid,low,high;
	low = 0;
	high = n-1;
	while(low <= high)
	{
		mid = (high+low)/2;
		if(x < v[mid])
		{
			high = mid - 1;
		}
		else if(x > v[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
