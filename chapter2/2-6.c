#include<stdio.h>

int setbits(int,int,int,int);

int main()
{			/*if i use getchar then its reads only single digit numbers correctly, while others are taken one char at a time..
			like '123' will be taken as 1 for x, 2 for y, 3 for p etc.*/
	int x,p,n,y;
	printf("enter x");
	x = 100;//x = getchar() - '0';
	printf("\nenter y");
	y = 50;//y = getchar() - '0';
	printf("\nenter p");
	p = 7;//p = getchar() - '0';
	printf("\nenter n");
	n = 3;//n = getchar() - '0';
	printf("\n%d\n",setbits(x,p,n,y));
	return 0;
}

int setbits(int x, int p , int n , int y)
{
	y = ~(~0 << n) & y;
    y = ((x >> p+1) << n) | y;
    x = ~(~0 << (p+1-n)) & x;
    y = (y << p+1-n) | x;
    return y;
}
