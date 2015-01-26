#include<stdio.h>

int rightrot(int,int);

int main()
{
	int x,n;
	x = 50;
	n = 3;
	printf("%d\n", rightrot(x,n));
	return 0;
}

int rightrot(int x, int n)
{
	int or,ol,count=0;
	or = (x & ~(~0 << n));	//original right part of the number....to be made the left part now
	ol = (x >> n);		//original left part of the number....to be made right now
	/*counting the number of set bits in 'ol'*/
	int temp = ol;
	while(temp)
	{
		temp = temp >> 1;	//shifting 1 bit right until it becomes 0....since a number 7(for eg.) will be like 00000111 in
		count++;	 	//8-bit representation
	}
	/*shifting 'or' left, equivalent to no. of bits in 'ol' i.e. 'count'*/
	or = or << count;
	return (or | ol);//using | instead of & since we want to set 'count' no. of right-bits of 'or' to 'ol'
}
