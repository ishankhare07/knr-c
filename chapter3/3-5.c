/*convert int to given base string of digits*/

#include<stdio.h>

int itob(int,char[],int);

int main() {
	int i,lim,b;
	char s[50];

	printf("Enter integer : ");
	scanf("%d",&i);

	printf("Enter base to convert to : ");
	scanf("%d",&b);

	lim = itob(i,s,b);

	for(i = lim ; s[i] > 0 ; i--) {
		printf("%c",s[i]);
	}

	printf("\n");

	return 0;
}


int itob(int i, char s[], int base) {
	int j = 0,rem;

	while(i) {
		rem = i % base;
		if(rem >= 10) {
			rem %= 10;
			s[j++] = rem + 'A';
		}
		else {
			s[j++] = rem + '0';
		}

		i /= base;
	}

	switch(base) {
		case 2 : s[j++] = 'b';
			break;
		case 8 : s[j++] = 'o';
			break;
		case 16 : s[j++] = 'x';
			break;
		default : break;
	}
	s[j] = '0';

	return j;
}
