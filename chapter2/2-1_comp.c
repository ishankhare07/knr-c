#include<stdio.h>
#include<math.h>

int main()
{
	//char
	printf("upper limit of char is : %.f\n",(pow(2,sizeof(char) * 8 - 1) -1));
	printf("lower limit of char is : %.f\n",-(pow(2,sizeof(char) * 8 - 1)));

	//unsigned char
	printf("upper limit of unsigned char is : %.f\n",(pow(2,sizeof(unsigned char) * 8) - 1));
	printf("lower limit of unsigned char is : %d\n",0);

	//short
	printf("upper limit of short is : %.f\n",(pow(2,sizeof(short) * 8 - 1) -1));
	printf("lower limit of short is : %.f\n",(pow(2,sizeof(short) * 8 - 1)));

	//unsigned short
	printf("upper limit of unsigned short is : %.f\n",(pow(2,sizeof(unsigned short) * 8) -1));
	printf("lower limit of unsigned short is : %d\n",0);

	//int
	printf("upper limit of int is : %.f\n",(pow(2,sizeof(int) * 8 - 1) -1));
	printf("lower limit of int is : %.f\n",(pow(2,sizeof(int) * 8 - 1)));

	//unsigned int
	printf("upper limit of unsigned int is : %.f\n",(pow(2,sizeof(unsigned int) * 8) -1));
	printf("lower limit of unsigned int is : %d\n",0);

	//long
	printf("upper limit of long is : %.f\n",(pow(2,sizeof(long) * 8 - 1) -1));
	printf("lower limit of long is : %.f\n",(pow(2,sizeof(long) * 8 - 1)));

	//unsigned long
	printf("upper limit of unsigned long is : %.f\n",(pow(2,sizeof(unsigned long) * 8) -1));
	printf("lower limit of unsigned long is : %d\n",0);

	return 0;
}
