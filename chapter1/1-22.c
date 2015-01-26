/*insert tab for a particular number of continuous spaces*/

#include<stdio.h>
#define MAXLENGTH 1000
#define TAB 5

int entab(char [], int);

int main()
{
	int c,i=0,j=0;
	char line[MAXLENGTH],prev = '\0',prevl = '\0';
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			if(prevl == '\n')
			{
				continue;
			}
			else
			{
				prevl = line[j] = c;
				++j;
			}
		}
		else if(c == ' ')
		{
			++i;
			if(prev == ' ')
			{
				continue;
			}
			if(i >= TAB)
			{
				j = entab(line,j);
				prevl = ' ';
				i = 0;
			}
		}
		else
		{
			if(i > 0 && i < TAB)
			{
				prevl = line[j] = ' ';
				++j;
			}
			i = 0;
			prevl = line[j] = c;
			++j;
		}
	}
	line[j] = '\0';
	printf("\n%s\n",line);
	return 0;
}


int entab(char s[], int i)
{
	int c = TAB;
	while(c > 0)
	{
		s[i] = ' ';
		--c;
		++i;
	}
	return i;
}
