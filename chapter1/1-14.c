#include<stdio.h>

int main()
{
	int c,i,j,freq[26];
	for(i = 0 ; i < 26 ; ++i)
	{
		freq[i] = 0;
	}
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			continue;
		}
		else
		{
			++freq[c-'a'];
		}
	}
	printf("\n");

	for(i = 0 ; i < 26 ; ++i)
	{
		putchar(i+'a');
		printf(" ");
		for(j = 0 ; j < freq[i] ; ++j)
		{
			printf("=");
		}
		printf(">\n");
	}
	return 0;
}
