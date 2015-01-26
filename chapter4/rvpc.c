/*reverse polish calculator*/

#include<stdio.h>
#include<stdlib.h>	//for atof()
#include<ctype.h>
#include<math.h>

#define MAX 100
#define NUMBER '0'
#define MAXVAL 100

int top = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop();

int main() {

	int type;
	char s[MAX];
	double op;

	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER :
				push(atof(s));
				break;
			case '+' :
				push(pop() + pop());	//since during push numbers already converted to float by atof
				break;
			case '*' :
				push(pop() * pop());
				break;
			case '-' :
				op = pop();
				push(pop() - op);
				break;
			case '/' :
				op = pop();
				if(op != 0) {
					push(pop() / op);
				}
				else {
					printf("error : division by zero");
				}
				break;
			case '\n' :
				printf("\n%.8g\n",pop());
				break;
			default :
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

int getop(char s[]) {
	int i,c;
	while((s[0] = c = getchar()) == ' ' || c == '\t');	//this and following line will skip all the leading spaces before a number or operator
	s[1] = '\0';

	if(!isdigit(c) && c != '.') {
		return c;	//not a number
	}

	i = 0;
	if(isdigit(c)) {	//collect integer part
		while(isdigit(s[i++] = c)) {
			c = getchar();
		}
	}

	if(c == '.') {
		s[i] = c;
		while(isdigit(s[i++] = c = getchar()));
	}

	s[i] = '\0';
	return NUMBER;
}

void push(double f) {
	if(top < MAXVAL) {
		val[top++] = f;
	}
	else {
		printf("error: stack full, can't push %g\n",f);
	}
}

double pop() {
	if(top > 0) {
		return val[--top];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
