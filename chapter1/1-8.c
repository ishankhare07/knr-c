#include<stdio.h>

int main()
{
	int c,bl,tb,nl;
	bl=tb=nl=0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			bl++;
		else if(c == '\t')
			tb++;
		else if(c == '\n')
			nl++;
		else
			continue;
	}
	printf("blanks : %d\ntabs : %d\nlines : %d\n",bl,tb,nl);
	return 0;
}
