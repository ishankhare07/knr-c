/*reverse polish calculator with modulus and negative numbers*/

#include<stdio.h>
#include<stdlib.h>	//for atof()
#include<ctype.h>
#include<math.h>

#define MAX 100
#define NUMBER '0'
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
			case '%' :
				op = pop();
				if(op != 0) {
					push(fmod(pop(),op));
				}
				else {
					printf("error : modulo by zero");
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
	while((s[0] = c = my_getch()) == ' ' || c == '\t');	//this and following line will skip all the leading spaces before a number or operator
	s[1] = '\0';
	i = 0;

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
