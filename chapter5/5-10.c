#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 20
#define NUMBER '0'

void parse(char *);
int getop(char *);
int pop();
void push(int);

int stack[SIZE];
int *stackptr = stack;

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("Usage: expr <reverse polish expression>\n");
        return 0;
    }

    while(*++argv) {
        parse(*argv);
    }

    return 0;
}

void parse(char *s) {
    int temp, type;
    float result;

    type = getop(s);
    switch(type) {
        case '+':
            result = pop() + pop();
            printf("%f\n", result);
            push(result);
            break;
        case '-':
            temp = pop();
            result = pop() - temp;
            printf("%f\n", result);
            push(result);
            break;
        case '*':
            result = pop() * pop();
            printf("%f\n", result);
            push(result);
            break;
        case '/':
            temp = pop();
            result = pop() / (temp * 1.0);
            printf("%f\n", result);
            push(result);
            break;
        case '%':
            temp = pop();
            result = pop() % temp;
            printf("%f\n", result);
            push(result);
            break;
        case NUMBER:
            push(atoi(s));
            break;
    }
}

int getop(char *s) {
    if(!isdigit(*s)) {
        return *s;
    } else {
        return NUMBER;
    }
}

int pop() {
    return *(--stackptr);
}

void push(int a) {
    *(stackptr++) = a;
}
