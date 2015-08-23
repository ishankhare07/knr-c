/*pointer version of strcat*/

#include <stdio.h>
#include "my_getline.h"
#define SIZE 50

char *strcat(char*, char*);

int main() {
    char a[SIZE], b[SIZE];
    printf("enter two strings");
    getl(a, SIZE);
    getl(b, SIZE);

    strcat(a, b);
    
    printf("%s\n",a);
    return 0;
}

char *strcat(char *s, char *t) {
    while(*s++);
    s--;

    while((*s++ = *t++));

    return s;
}
