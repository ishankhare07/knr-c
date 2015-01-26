#include<stdio.h>

int main()
{
	int c,word = 0,bl = 1;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			bl++;
		}
		else if(bl > 0)
		{
			word++;
			bl = 0;
		}
	}
	printf("word : %d\n",word);
	return 0;
}
