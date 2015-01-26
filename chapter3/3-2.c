#include<stdio.h>
#define size 50

void escape(char[],char[],int);

int main()
{
	int i,c;
	char s[size],t[size];
	for(i = 0 ; (i < size) && (c = getchar()) != EOF ; i++)
	{
		s[i] = c;
	}
	escape(s,t,i);
	for(c = 0 ; c < i ; c++)
		printf("%c",t[c]);
	return 0;
}

void escape(char s[], char t[],int limit)
{
	int i,j;
	for(i = 0, j = 0 ; i <= limit && j < size ; i++,j++)
	{
		switch(s[i])
		{
			case '\n' :
				t[j] = '\\';
				j++;
				t[j] = 'n';
				break;
			case '\t' :
				t[j] = '\\';
				j++;
				t[j] = 't';
				break;
			default :
				t[j] = s[i];
				break;
		}
	}
}
