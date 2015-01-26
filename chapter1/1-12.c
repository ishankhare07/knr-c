#include<stdio.h>

int main()
{
	int c,bl = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t')
			++bl;
		else
		{
			if(bl > 0)
			{
				printf("\n");
				bl = 0;
			}
			putchar(c);
		}
	}
	return 0;
}
