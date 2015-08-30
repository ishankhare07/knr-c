#include <stdio.h>

int getl(char *s, int limit) {
    int size=0, c;

    while((c = getchar()) != EOF && c != '\n' && size < limit) {
        *s++ = c;
        size++;
    }

    *s = '\0';

    return size;
}
