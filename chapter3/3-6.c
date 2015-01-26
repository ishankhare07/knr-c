/*itoa with 3rd argument of min. field width*/

#include<stdio.h>
#define size 50

void itoa(int, char[], int);

int main() {
	int n,m;
	char s[size];

	printf("Enter the number : ");
	scanf("%d",&n);

	printf("Enter minimum field width : ");
	m = getchar() - '0';

	itoa(n,s,m);
	return 0;
}


void itoa(int n, char s[], int m) {
	int i,temp;
	for(i = 0; (i < size) && n ; i++) {
		temp = n % 10;
		s[i] = temp + '0';
		n /= 10;
	}

	if(i < m) {
		for(i; (i <= m) && (i < size) ; i++) {
			s[i] = '0';
		}
	}

	i--;

	for(i; i >= 0 ; i--) {
		printf("%c",s[i]);
	}

	printf("\n");
}
