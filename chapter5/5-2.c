#include <stdio.h>
#include <ctype.h>
#include "../lib/get.h"
#define SIZE 20

int getint(float *pn) {
    int c, sign;
    float power;

    while(isspace(c = getch()));        //skip whitespaces
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                     //not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-') {
        c = getch();
        if(!isdigit(c)) {               //+ or - at end
            ungetch(c);
            return EOF;
        }
    }

    for(*pn = 0; isdigit(c); c = getch()) {
        *pn = 10.0 * (*pn) + (c - '0');
    }

    if(c == '.') {
        c = getch();
    }

    for(power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }

    *pn *= sign/power;
    if(c != EOF) {
        ungetch(c);
    }

    return c;
}

int main() {
    int n, i;
    float array[SIZE];
    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++);

    for(i = 0; i < n; i++) {
        printf("%f\n",array[i]);
    }
    return 0;
}
