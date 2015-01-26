#include<stdio.h>

int htoi(char[]);

int main()
{
	char in[3];
	int i,c;
	printf("Enter a hex number : ");
	for(i = 0 ;i<3 && (c=getchar()) != EOF && c != '\n'; ++i)
	{
		in[i] = c;
	}
	if(i < 3)
	{
		in[i] = '\n';
	}
	c = htoi(in);
	if(c >= 0)
	{
		printf("Equivatent decimal value = %d\n",c);
	}
	else
	{
		printf("Error!");
	}
	return 0;
}

int htoi(char in[])
{
	int i = 0,r;
	while(i < 3 && in[i] != EOF && in[i] != '\n')
	{
		if(i == 0 && in[i] == '0' && in[i+1] == ('x' || 'X'))
		{
			i = 1;
		}
		else if(in[i] >= '0' && in[i] <= '9')
		{
			r =  (in[i] - '0');
		}
		else if(in[i] >= 'a' && in[i] <= 'f')
		{
			r =  (in[i] - 'a') + 10;
		}
		else if(in[i] >= 'A' && in[i] <= 'F')
		{
			r = (in[i] - 'A') + 10;
		}
		else
		{
			r = -1;
		}
		++i;
	}
	return r;
}
