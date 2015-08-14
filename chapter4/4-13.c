#include <stdio.h>
#include "4-13-lib.h"
#define MAX 50

int main() {
    char s[50];
    char c;
    int i=0;

    while((c = getchar()) != EOF) {
        if(c != '\n') {
            s[i++] = c;
        } else {
            s[i] = '\0';
            reverse(s);
            printf("%s\n", s);
            i = 0;
        }
    }

    return 0;
}
