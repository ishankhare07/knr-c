/*reverse polish calculator with modulus and negative numbers and other features*/

#include<stdio.h>
#include<stdlib.h>	//for atof()
#include<ctype.h>
#include<math.h>
#include<string.h>

#define MAX 100
#define NUMBER '0'
#define NAME 'n'
#define MAXVAL 100

int top = 0;
double val[MAXVAL];
char buf[MAX];
int bufp = 0;

int getop(char []);
void push(double);
double pop();
int my_getch();
void ungetch(int);
void mathfunc(char[]);

int main() {

	int type;
	char s[MAX];
	double op,op2;

	while((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER :
				push(atof(s));
				break;
			case NAME :
				mathfunc(s);
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
			case '%' :
				op = pop();
				if(op != 0) {
					push(fmod(pop(),op));
				}
				else {
					printf("error : modulo by zero");
				}
				break;
			case '?' :		//print top of stack without popping
				op = pop();
				printf("top of stack : %f\n",op);
				push(op);
				break;
			case '~' :		//duplicating top of stack
				op = pop();
				push(op);
				push(op);
				break;
			case '<' :		//swap top 2 elements
				op = pop();
				op2 = pop();
				push(op);
				push(op2);
				break;
			case '>' :		//clear the stack
				while(op = pop()) {
					printf("%f\n",op);
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

void mathfunc(char s[]) {
	double op2;
	if(strcmp(s,"sin") == 0) {
		push(sin(pop()));
	}
	else if(strcmp(s,"cos") == 0) {
		push(cos(pop()));
	}
	else if(strcmp(s,"exp") == 0) {
		push(exp(pop()));
	}
	else if(strcmp(s,"pow") == 0) {
		op2 = pop();
		push(pow(pop(),op2));
	}
	else {
		printf("error : %s not supported\n",s);
	}
}

int getop(char s[]) {
	int i,c;
	while((s[0] = c = my_getch()) == ' ' || c == '\t');	//this and following line will skip all the leading spaces before a number or operator
	s[1] = '\0';
	i = 0;

	if(islower(c)) {					//name or command
		s[i++] = c;
		while(islower(c = my_getch())) {
			s[i++] = c;
		}
		s[i] = '\0';
		if(c != EOF) {
			ungetch(c);
		}
		if(strlen(s) > 1) {
			return NAME;
		}
		else {
			return c;
		}
	}

	if(c == '-') {
		if(isdigit(c = my_getch()) || c == '.') {
			s[i++] = '-';
		}
		else {
			ungetch(c);
			return '-';
		}
	}

	if(!isdigit(c) && c != '.') {
		return c;	//not a number
	}

	if(isdigit(c)) {	//collect integer part
		while(isdigit(s[i++] = c)) {
			c = my_getch();
		}
	}
	if(c == '.') {
                s[i] = c;
                while(isdigit(s[i++] = c = my_getch()));
        }

	s[i] = '\0';
	if(c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

int my_getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp > MAX) {
		printf("ungetch : too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
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
