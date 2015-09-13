#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINESIZE 1000

int main(int argc, char *argv[]) {
    FILE *first, *second;
    char line[LINESIZE], line2[LINESIZE];
    int flag = 0;

    if(argc != 3) {
        fputs("Usage: diff <file1> <file2> ", stderr);
        printf("%d", argc);
        exit(1);
    } else {
        first   = fopen(*++argv, "r");
        second  = fopen(*++argv, "r");

        if(first == NULL || second == NULL) {
            fputs("Error: unable to open one of the files", stderr);
            exit(1);
        }

        while(fgets(line, LINESIZE, first) && fgets(line2, LINESIZE, second)) {
            if(strcmp(line, line2) != 0) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            fputs(line, stdout);
            fputs(line2, stdout);
        }
    }

    fclose(first);
    fclose(second);

    return 0;
}
