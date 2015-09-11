#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_getline.h"
#define SIZE 20
#define HASHVAL 101

struct node {
    struct node *next;
    char *key;
    char *value;
};

struct node *hashtable[HASHVAL];

struct node *lookup(char *);
void insert(char *, char *);
unsigned int hash(char *);
int undef(char *);

int main() {
    int ch = 1;
    char temp[SIZE];
    char *key, *value;
    int length;

    struct node *p;

    while(ch != 4) {
        printf("1. Create\n2. Get \n3. Remove\n4. Exit\n\n");
        scanf("%d", &ch);
        while(getchar() != '\n');
        length = 0;

        switch(ch) {
            case 1:
                printf("Enter key: ");
                length  = getl(temp, SIZE);

                if(!length) {
                    printf("error: empty key %d\n", length);
                    break;
                } else {
                    key = strdup(temp);
                }

                printf("Enter value: ");
                length = getl(temp, SIZE);

                if(!length) {
                    printf("error: empty value\n");
                    break;
                } else {
                    value = strdup(temp);
                }
                insert(key, value);
                break;
            case 2:
                printf("enter key: ");
                length = getl(temp, SIZE);

                if(length) {
                    if((p = lookup(temp))) {
                        printf("%s\n", p->value);
                    } else {
                        printf("not found\n");
                    }
                } else {
                    printf("empty value\n");
                }
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("worng choice\n");
                break;
            case 3:
                printf("enter key: ");
                length = getl(temp, SIZE);

                if(length) {
                    if(undef(temp)) {
                        printf("successfully removed\n");
                    } else {
                        printf("value not found\n");
                    }
                } else {
                    printf("Error: input value empty");
                }
                break;
        }
    }
    return 0;
}

unsigned hash(char *key) {
    unsigned hashval;
    for(hashval = 0; *key != '\0'; key++) {
        hashval += (*key + 31) % HASHVAL;
    }

    return hashval;
}

struct node *lookup(char *key) {
    struct node *n;

    for(n = hashtable[hash(key)]; n != NULL; n = n->next) {
        if(strcmp(key, n->key) == 0) {
            return n;                               // already exists
        }
    }

    return NULL;
}

void insert(char *key, char *value) {
    struct node *p;
    unsigned hashval;

    if((p = lookup(key)) == NULL) {                       // does not exist
        p = (struct node *) malloc(sizeof (*p));
        p->key              = key;
        hashval             = hash(key);
        p->next             = hashtable[hashval];
        hashtable[hashval]  = p;
    } else {                                        // exists
        free((void *) p->value);
    }

    p->value = strdup(value);
}

int undef(char *s) {
    struct node *n, *prev=NULL;
    int cond;
    unsigned h = hash(s);

    for(n = hashtable[h]; n != NULL; n = n->next) {
        if((cond = strcmp(s, n->key)) == 0 && prev != NULL) {
            prev->next = n->next;
            free((void *) n->key);
            free((void *) n->value);
            free((void *) n);
            return 1;
        } else if(!cond) {                          // first node
            hashtable[h] = n->next;
            free((void *) n->key);
            free((void *) n->value);
            free((void *) n);
            return 1;
        }
        prev = n;
    }
    return 0;
}
