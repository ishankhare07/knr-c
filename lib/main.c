#include <stdio.h>
#include "lib/get.h"

int main() {
    char c;
    while((c = getch()) != EOF && c != '\n') {
        putchar(c);
    }

    putchar('\n');
    
    return 0;
}
