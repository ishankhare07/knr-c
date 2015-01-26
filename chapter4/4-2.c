#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 10

int getl(char arr[], int limit) {
	char c;
	int i;

	for(i = 0 ; (i < limit) && (c = getchar()) != '\n' && (c != EOF) ; i++) {
		arr[i] = c;
	}
	if(c == '\n') {
		arr[i++] = '\n';
	}

	arr[i] = '\0';
	return i;
}

double atof(char s[], int upper) {
	int i,sign,n=0,exp_sign = 1;
	double val,dec,exp=1.0;

	for(i = 0 ; isspace(s[i]) ; i++);	//skip whitespace

	sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '-' || s[i] == '+') {
		i++;
	}

	for(val = 0.0 ; isdigit(s[i]) ; i++) {
		val = 10.0 * val + (s[i] - '0');
	}

	if(s[i] == '.') {
		i++;
		//printf("detected decimal\n");
	}

	for(dec = 1.0 ; isdigit(s[i]) ; i++) {
		val = 10 * val + (s[i] - '0');
		dec *= 10.0;
	}

	val = sign * val / dec;

	if(s[i] == 'e' || s[i] == 'E') {
		i++;
		if(s[i] == '-') {
			exp_sign = -1;
			i++;
		}

		while(isdigit(s[i]) && i < upper) {
			n = 10 * n + (s[i] - '0');
			i++;
		}

		while(n) {
			if(!exp_sign) {
				exp *= 10;
			}
			else {
				exp /= 10;
			}
			n--;
		}

	}
	return val * exp;
}

int main() {
	char line[size];
	int i;

	while((i = getl(line,size)) > 0) {
		printf("%f\n",atof(line,i));
	}

	return 0;
}
