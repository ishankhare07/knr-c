#include<stdio.h>

int main()
{
	float farh,celsius;
	int step,lower,upper;
	lower = 0;
	upper = 300;
	step = 20;
	farh = lower;
	printf("farhenheit-celsius conversion table\n");

	while(farh <= upper)
	{
		celsius = (5/9.)*(farh-32.);
		printf("%3.0f %6.1f\n",farh,celsius);
		farh = farh + step;
	}
	return 0;
}
