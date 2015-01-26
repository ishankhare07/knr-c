/*convert a string of numbers into an integer*/

#include<stdio.h>
#include<ctype.h>
#define size 50

int atoi(char[]);

int main() {
	char c,s[size];
	int i;
	for(i = 0 ; (i < size) && (c = getchar()) != EOF ; i++) {
		s[i] = c;
	}
	printf("\n%d\n",atoi(s));
	return 0;
}

int atoi(char s[]) {
	int i,n,sign=1;

	for(i = 0 ; isspace(s[i]) ; i++);	//skip white spaces

	if(s[i] == '-') {			//acknowledge and skip sign
		sign = -1;
		i++;
	}
	else if(s[i] == '+') {
		sign = 1;
		i++;
	}

	for(n = 0 ; isdigit(s[i]) ; i++) {
		n = 10 * n + (s[i] - '0');
	}

	return sign * n;
}
