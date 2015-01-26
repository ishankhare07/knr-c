#include<stdio.h>

int main()
{
	int c,bl = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			bl++;
		}
		else
		{
			if(bl > 0)
			{
				printf(" ");
				bl = 0;
			}
			putchar(c);
		}
	}
	return 0;
}
