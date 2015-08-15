#include <stdio.h>
#include "4-13-lib.h"
#define MAX 50

void itoa(int a, char s[]) {
    void convert(int, char[], int);

    convert(a, s, 0);

    reverse(s);
}

int main() {
    char s[MAX];
    int number;

    printf("enter a number");
    scanf("%d", &number);
    itoa(number, s);

    printf("%s\n", s);

    return 0;
}

void convert(int a, char s[], int index) {
    if(a < 0) {
        s[index] = '-';
        a = -a;
        convert(a, s, ++index);
    }

    s[index] = a % 10 + '0';

    if(a > 0) {
        convert(a/10, s, ++index);
    } else {
        s[index] = '\0';
        return;
    }
}
