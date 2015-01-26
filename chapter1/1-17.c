/*program to print all the input lines that are longer than 80 char*/

#include<stdio.h>
#define LENGTH 80
#define MAX 1000

int getl(char [], int);

int main()
{
	int len;
	char line[MAX];
	while((len = getl(line,MAX)) > 0)
	{
		if(len > LENGTH)
		{
			printf("\n%s\n",line);
		}
	}
	return 0;
}

int getl(char s[], int lim)
{
	int c,i;
	for(i = 0 ; i < lim && (c = getchar()) != '\n' && c != EOF ; ++i)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		++i;
		s[i] = '\0';
	}
	return i;
}
