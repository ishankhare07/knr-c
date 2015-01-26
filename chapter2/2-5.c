/*program to return first occurence of char of string s2 in string s1*/

#include<stdio.h>
#define size 20

void getl(char s[])
{
	int i,c;
	for(i = 0 ; i < size-1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i++] = '\n';
	}
	s[i] = '\0';
}

int any(char s1[], char s2[])
{
	int i=0,j,pos = -1;
	while(s1[i] != '\0')
	{
		j = 0;
		while(s2[j] != '\0')
		{
			if(s1[i] == s2[j])
			{
				pos = i;
				break;
			}

			++j;
		}
		if(pos == i)
		{
			break;
		}
		++i;
	}
	return pos+1;
}

int main()
{
	char s1[size],s2[size];
	getl(s1);
	getl(s2);
	printf("Position = %d\n",any(s1,s2));
	return 0;
}
