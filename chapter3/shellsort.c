#include<stdio.h>
#define size 20

void shellsort(int[],int);

int main() {
	int n,i;
	int s[size],c;

	for(i = 0, n = 0 ; (i < size) && (c=getchar()) != EOF ; i++) {
		s[i] = c - '0';
		n++;
	}

	n--;

	for(i = 0 ; i < n ; i++) {
		printf("\n%d ",s[i]);
	}

	shellsort(s,n);
	for(i = 0 ; i < n ; i++) {
		printf("\n%d ",s[i]);
	}

	return 0;
}


void shellsort(int v[], int n) {
	int gap,i,j,temp;

	for(gap = n/2 ; gap > 0 ; gap /= 2) {
		for(i = gap ; i < n ; i++) {
			for(j = i-gap ; (j >= 0) && (v[j] > v[j+gap]) ; j -= gap) {
				temp = v[j+gap];
				v[j+gap] = v[j];
				v[j] = temp;
			}
		}
	}
}
