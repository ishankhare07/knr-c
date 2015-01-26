/*printing limits of char,short,int and long (both signed and unsigned) using standard headers (limits.h)*/

#include<stdio.h>
#include<limits.h>

int main()
{
	printf("max value of char : %d\n",CHAR_MAX);
	printf("min value of char : %d\n",CHAR_MIN);
	printf("max value of unsigned char : %d\n",UCHAR_MAX);
	printf("min value of unsigned char : %d\n",0);
	printf("max value of signed char : %d\n",SCHAR_MAX);
	printf("min value of signed char : %d\n",SCHAR_MIN);
	printf("max value of int : %d\n",INT_MAX);
	printf("min value of int : %d\n",INT_MIN);
	printf("max value of long : %ld\n",LONG_MAX);
	printf("min value of long : %ld\n",LONG_MIN);
	printf("max value of short : %d\n",SHRT_MAX);
	printf("min value of short : %d\n",SHRT_MIN);
	printf("max value of unsigned int : %d\n",UINT_MAX);
	printf("min value of unsigned int : %d\n",0);
	printf("max value of unsigned long : %lu\n",ULONG_MAX);
	printf("max value of unsigned short : %d\n",USHRT_MAX);
	return 0;// hey I've edited this from phone ;)
}