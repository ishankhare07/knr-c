//getch and ungetch implementation

//#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

char getch() {
    if(bufp > 0) {
        return buf[--bufp];
    } else {
        return getchar();
    }
}

void ungetch(char c) {
    if(bufp >= BUFSIZE) {
        printf("Too many characters!");
    } else {
        buf[bufp++] = c;
    }
}
