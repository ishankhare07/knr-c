#include<stdio.h>

int main()
{
	int farh;
	for(farh = 300 ; farh >= 0 ; farh -= 20)
	{
		printf("%3d %6.1f\n",farh,(5.0/9.0)*(farh-32.0));
	}
	return 0;
}
