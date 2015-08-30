// quick sort based implementation for sorting lines lexicographically

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_getline.h"
#define SIZE 50
#define MAXLINES 20

void quicksort(char *[], int, int);
void swap(char **, int, int);
void writelines(char **, int);
int stringcmp(char *, char *);

int main() {
    char l[SIZE];
    char *sentences[MAXLINES];
    char *p;
    int length, lines=0;

    for( ; (length = getl(l, SIZE)) > 0 && lines < MAXLINES; lines++ ) {
        p = (char*) malloc(sizeof(char) * length);
        strcpy(p, l);
        sentences[lines] = p;
    }

    quicksort(sentences, 0, lines);
    writelines(sentences, lines);

    return 0;
}

void writelines(char **sentences, int lines) {
    while(lines) {
        printf("%s\n", *sentences);
        lines--;
        sentences++;
    }
}

void quicksort(char *sentences[], int left, int right) {
    int i, last;

    if (left >= right) {
        return;
    }

    swap(sentences, left, (left + right) / 2);
    last = left;
    for(i = left+1; i <= right; i++) {
        if(strcmp(sentences[i], sentences[left]) > 0) {
            swap(sentences, ++last, i);
        }
    }
    
    swap(sentences, left, last);
    quicksort(sentences, left, last-1);
    quicksort(sentences, last+1, right);
}

void swap(char **v, int i, int j) {
    char *temp;

    temp = v[i];            // only swapping the pointers
    v[i] = v[j];
    v[j] = temp;
}

int stringcmp(char *s, char *t) {
    while(*s == *t) {
        if(*s == '\0') {
            return 0;
        }
        printf("s-> %s t-> %s", s, t);
        s++;
        t++;
    }

    return *s - *t;
}
