/*convert uppercase to lower using conditional expression ? : */

#include<stdio.h>
#include<ctype.h>

void lower(char);

int main()
{
	char c;
	while((c=getchar()) != EOF)
	{
		islower(c) ? putchar(c) : (isupper(c) ? lower(c) : putchar(c));
	}
	return 0;
}

void lower(char a)
{
	putchar(a + ' ');
}
