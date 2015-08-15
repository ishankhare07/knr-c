#include <stdio.h>

int getl(char *s, int limit) {
    int size, c;

    while((c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        size++;
    }

    *s = '\0';

    return size;
}
