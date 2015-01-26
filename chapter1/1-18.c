/*remove trailing blanks tabs and delete entire blank lines*/

#include<stdio.h>
#define MAXLENGTH 1000

int getl(char [], int);
int main()
{
	int len;
	char line[MAXLENGTH];
	while((len = getl(line,MAXLENGTH)) > 0)
	{
		printf("\n%s\n",line);
	}
	return 0;
}

int getl(char s[], int lim)
{
	int c,i = 0;
	char prev = '\0';
	while(i < lim && (c = getchar()) != EOF)
	{
		if(c == ' ' && prev == ' ')
		{
			continue;
		}
		else if(c == '\t' && (prev == '\t' || prev == ' '))
		{
			prev = '\t';
		}
		else if(c == '\n' && (prev == '\t' || prev == ' '))
		{
			s[i] = c;
			++i;
		}
		else if(c == '\n' && prev == '\n')
		{
			continue;
		}
		else
		{
			prev = c;
			s[i] = c;
			++i;
		}
	}
	s[i] = '\0';
	return i;
}
