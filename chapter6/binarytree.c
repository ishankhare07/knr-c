#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/get.h"
#include "../lib/getword.h"
#define MAXWORD 100

struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

struct node *addtree(struct node*, char *);
int getword(char *, int);
void treeprint(struct node*);

int main() {
    struct node *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    treeprint(root);
    return 0;
}

struct node *addtree(struct node *p, char *w) {
    int cond;

    if(p == NULL) {                                         // new word
        p = (struct node*) malloc(sizeof (struct node));
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0) {           // repeated word
        printf("exists\n");
        p->count++;
    } else if(cond < 0) {                                   // into left subtree
        printf("left\n");
        p->left = addtree(p->left, w);
    } else {
        printf("right %d\n", cond);
        p->right = addtree(p->right, w);
    }

    return p;
}

void treeprint(struct node *p) {
    if(p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
