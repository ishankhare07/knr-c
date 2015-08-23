/*implementation of UNIX find command with optional command-line agruments*/

#include <stdio.h>
#include <string.h>
#include "../lib/my_getline.h"
#define MAXLINE 1000

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while(--argc > 0 && (*++argv)[0] == '-') {
        while(c = *++argv[0]) {                     //notice the different between (*++argv)[0] and *++argv[0]
            switch(c) {                             // [] has more precedence than *
                case 'n':
                    number = 1;
                    break;

                case 'x':
                    except = 1;
                    break;

                default:
                    printf("find: illegal option %c\n",c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if(argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while(getl(line, MAXLINE) > 0) {
            lineno++;
            if((strstr(line, *argv) != NULL) != except) {
                if(number) {
                    printf("%ld:", lineno);
                }

                printf("%s\n", line);
                found++;
            }
        }
    }

    return found;
}
