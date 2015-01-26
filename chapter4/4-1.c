/*function to return rightmost index of a string in another*/

#include<stdio.h>
#define size 1000

int strindex(char[], char[]);
int getl(char[],int);
int len(char[]);

int main() {
	char line[size],t[]="hare";

	while(getl(line,size) > 0) {
		printf("rightmost index is : %d\n",strindex(line,t));
	}
	return 0;
}

int getl(char s[], int limit) {
	int i,j;

	for(i = 0 ; (i < limit) && (j = getchar()) != EOF && j != '\n' ; i++) {
		s[i] = j;
	}

	if(j == '\n') {
		s[i++] = j;
	}

	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[]) {
	int i,j,k,l;

	for(i = len(s) ; i >= 0 ; i--) {
		for(j = len(t), k = i ; (j >= 0) && (s[k] == t[j]) ; k--,j-- );
		if(j == -1) {
			return ++i;
		}
	}

	printf("%d %d\n",i,j);
	return -1;
}

int len(char a[]) {
	int i;
	for(i = 0 ; a[i] != '\0' ; i++);

	return i-1;
}
