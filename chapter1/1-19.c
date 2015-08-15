/*reverse a string*/

#include<stdio.h>
#define MAXLENGTH 1000

int getl(char [], int);
void reverse(char [], int);

int main()
{
	int len;
	char line[MAXLENGTH];
	while((len = getl(line,MAXLENGTH)) > 0)
	{
		reverse(line,len);
	}
	return 0;
}

int getl(char s[], int lim)
{
	int i,c;
	for(i = 0 ; i < lim && (c = getchar()) != EOF && c != '\n' ; ++i)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = '\0';
	}
	return i;
}

void reverse(char s[], int lim)
{
	int i,j;
	char rev[MAXLENGTH];
	for(i = lim-1, j = 0 ; i >= 0 ; --i,++j)
	{
		rev[j] = s[i];
	}
    rev[j] = '\0';
	printf("\n%s\n",rev);
}
