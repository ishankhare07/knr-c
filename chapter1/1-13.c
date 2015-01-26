#include<stdio.h>

int main()
{
	int c,i,j,length[10];
	for(i = 0 ; i < 10 ; ++i)
		length[i] = 0;
	i = 0;
	while((c = getchar()) != EOF && i < 10)
	{
		if(c == ' ' || c == '\t' || c == '\n')
			++i;
		else
			++length[i];
	}
	printf("\n");
	for(i = 0 ; i < 10 ; ++i)
	{
		printf("%d ",i);
		for(j = 0 ; j < length[i] ; ++j)
		{
			printf("=");
		}
		printf(">\n");
	}
	return 0;
}
