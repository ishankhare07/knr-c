#include <stdio.h>
#include "../lib/my_getline.h"
#define SIZE 50

int strend(char*, char*);

int main() {
    char s[SIZE], t[SIZE];

    getl(s, SIZE);
    getl(t, SIZE);

    printf("%d\n",strend(s, t));

    return 0;
}

int strend(char *s, char *t) {
    char *start = t;

    while(*s) {
        if(*s == *t) {
            s++;
            t++;
        } else if(!(*t)) {
            return 0;           // t exhausted but s not exhausted
        } else {
            t = start;          // reset t to starting
            if(*t == *s) {      // check if starting of t matches s
                continue;       // if yes then don't increment s, let it be handled by the 1st if case
            } else {
                s++;            // it does not match, so just start matching with next char
            }
        }
    }

    if(*t) {                // t not exhausted
        return 0;           // not matched as s is exhausted
    } else {
        return 1;
    }
}
