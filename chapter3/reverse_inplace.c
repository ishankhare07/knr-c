#include<stdio.h>
#define size 50

void reverse(char[],int);

int main() {
	int i,n;
	char s[size],c;

	for(i = 0 ; (i < size) && (c = getchar()) != EOF ; i++) {
		s[i] = c;
	}

	n = i-1;

	reverse(s,n);

	for(i = 0 ; i <= n ; i++) {
		printf("%c",s[i]);
	}

	printf("\n");

	return 0;
}

void reverse(char s[], int n) {
	int i,j;

	for(i = 0 ; i < n ; i++,n--) {
		j = s[i];
		s[i] = s[n];
		s[n] = j;
	}
}
