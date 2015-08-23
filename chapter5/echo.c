/*implementation of the unix echo command, using command-line arguments*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    while(--argc) {
        printf("%s%s", *(++argv), (argc > 1) ? " " : "");
    }

    printf("\n");

    return 0;
}
