/*program do delete each character in s1 that matches ant char in string s2*/

#include<stdio.h>
#define size 50

void getl(char[]);
void squeeze(char[],char[]);

int main()
{
	char s1[size],s2[size];
	getl(s1);
	getl(s2);
	squeeze(s1,s2);
	printf("%s%s\n",s1,s2);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i=0,j;
	while(s1[i] != '\0')
	{
		j = 0;
		while(s2[j] != '\0')
		{
			if(s2[j] == s1[i])
			{
				s2[j] = '_';
			}
			++j;
		}
		++i;
	}
}

void getl(char s[])
{
	int i,c;
	for(i = 0; i < size-1 && (c = getchar()) != EOF && c != '\n';++i)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
}
