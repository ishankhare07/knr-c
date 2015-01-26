/*count digits, white spaces, others*/
#include<stdio.h>

int main()
{
	int i,c,digits[10],white,others;
	white = others = 0;
	for(i = 0 ; i < 10 ; i++)
		digits[i] = 0;
	while((c = getchar()) != EOF)
	{
		switch(c)
		{
			case '0' : case '1' : case '2' : case '3' : case '4' : case '5' :
			case '6' : case '7' : case '8' : case '9' :
				++digits[c - '0'];
				break;
			case ' ' : case '\n' : case '\t' :
				white++;
				break;
			default : others++;
				break;
		}
	}
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d ",digits[i]);
	}
	printf("\n%d",white);
	printf("\n%d",others);
	return 0;
}
