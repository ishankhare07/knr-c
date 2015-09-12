#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[]) {
    FILE *fp;
    char *prog = *argv;

    if(argc > 1) {              // command line args exist
        while(--argc) {
            if((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    } else {                    // no command line arguments, read from stdin
        filecopy(stdin, stdout);
    }

    return 0;
}

void filecopy(FILE *inf, FILE *outf) {
    int c;

    while((c = getc(inf)) != EOF) {
        putc(c, outf);
    }
}
