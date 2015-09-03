// implements function pointer for quicksort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_getline.h"
#define SIZE 100
#define MAXLINES 50

void quicksort(void **s, int left, int right, int (*)(void *, void *));
void swap(void **, int, int);
void writelines(char **, int);
int numcmp(char *, char *);

int reverse = 0;

int main(int argc, char *argv[]) {
    char *sentences[MAXLINES];
    char line[SIZE], *p;
    int length, lines = 0, numeric = 0;

    if(argc > 1) {                          // scanning for options
        while(--argc && *argv++) {
            if((*argv)[0] == '-') {
                while(*++argv[0]) {
                    switch(*argv[0]) {
                        case 'r':
                            reverse = 1;
                            break;
                        case 'n':
                            numeric = 1;
                            break;
                        default:
                            printf("Usage: ./5-14 -rn\n");
                    }
                }
            }
        }
    }

    while((length = getl(line, SIZE)) && length > 0) {
        p = (char *) malloc(sizeof (char) * length);
        strcpy(p, line);
        sentences[lines++] = p;
    }

    quicksort((void **) sentences, 0, lines - 1, (int (*)(void *, void *)) (numeric ? numcmp : strcmp));
    writelines(sentences, lines);

    return 0;
}

void writelines(char **s, int lines) {
    while(lines--) {
        printf("%s\n", *s++);
    }
}

void swap(void **s, int a, int b) {
    void *temp;
    temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

int numcmp(char *a, char *b) {
    float x,y;

    x = atof(a);
    y = atof(b);

    if(x == y) {
        return 0;
    } else {
        return x - y;
    }
}

void quicksort(void **s, int left, int right, int (*comp)(void *, void *)) {
    int i, last;

    if(left > right) {
        return;
    }

    swap(s, left, (left + right) / 2);
    last = left;
    for(i = left+1; i <= right; i++) {
        if(reverse && (comp(s[i], s[left]) > 0)) {
            swap(s, ++last, i);
        } else if(!reverse && (comp(s[i], s[left]) < 0)) {
            swap(s, ++last, i);
        }
    }

    swap(s, left, last);
    quicksort(s, left, last-1, comp);
    quicksort(s, last+1, right, comp);
}

