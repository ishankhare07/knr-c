/*detab spaces*/

#include<stdio.h>
#define TABSIZE 3
#define MAX 1000

int tab(char [],int);

int main()
{
	int c,i=0;
	char line[MAX],prev = '\0';
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			if(prev == '\n')
			{
				continue;
			}
			else
			{
				prev = line[i] = c;
				++i;
			}
		}
		else if(c == '\t')
		{
			i = tab(line,i);
			prev = '\t';
		}
		else
		{
			prev = line[i] = c;
			++i;
		}
	}
	printf("\n%s\n",line);
	return 0;
}

int tab(char s[],int index)
{
	int tb = TABSIZE;
	for(tb ; tb > 0 ; --tb)
	{
		s[index] = ' ';
		++index;
	}
	return index;
}
