#include<stdio.h>

int main()
{
	float farh,celsius;
	int upper,step;
	celsius = 0;
	upper = 300;
	step = 20;
	while(celsius <= upper)
	{
		farh = (9.0*celsius)/5.0+32.0;
		printf("%3.f %6.1f\n",celsius,farh);
		celsius = celsius + step;
	}
	return 0;
}
