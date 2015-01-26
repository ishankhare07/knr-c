#include<stdio.h>

float convert(int);

int main()
{
	int step,lower,upper,farh;
	farh = lower = 0;
	upper = 300;
	step = 20;
	while(farh <= upper)
	{
		printf("%3d %6.1f\n",farh,convert(farh));
		farh += step;
	}
	return 0;
}

float convert(int farh)
{
	return ((5/9.) * (farh-32.));
}
