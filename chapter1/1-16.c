#include<stdio.h>
#define MAXLINE 1000

int getl(char [], int); //using the name 'getl' instead of 'getline' as 'getline' conflicts with the predefined 'getline' in stdio.h
void copy(char to[] , char from[]);

int main()
{
	int len,max;
	char line[MAXLINE], longest[MAXLINE];
	max = 0;
	while((len = getl(line,MAXLINE)) > 0)
	{
		printf("%d %s",len,line);
		if(len > max)
		{
			max = len;
			copy(longest,line);
		}
	}

	if(max > 0)
	{
		printf("%s",longest);
	}
	return 0;
}


int getl(char s[], int lim)
{
	int c,i;
	for(i = 0 ; i <lim-1 && (c = getchar()) != EOF && c != '\n' ; ++i)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
