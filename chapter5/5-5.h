#include <stdio.h>
#include "../lib/my_getline.h"
#define MAX 100

char *strncpy(char*, char*, int);
char *strncat(char*, char*, int);
int strncmp(char*, char*, int);

int strncmp(char *s, char *t, int n) {
    while(n-- && *s++ == *t++) {
        if(*t == '\0') {
            return *s - *t;
        }
    }
    return 0;
}

char *strncpy(char *s, char *t, int n) {
    int flag = 0;
    while(n--) {
        if(*t == '\0') {
            flag = 1;
        }

        if(flag) {
            *s++ = '\0';
        } else {
            *s++ = *t++;
        }
    }

    return s;
}

char *strncat(char *s, char *t, int n) {
    while(n-- && (*s++ = *t++));
    return *s;
}
