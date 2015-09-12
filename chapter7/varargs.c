#include "stdio.h"
#include <stdarg.h>

void minprintf(char *, ...);

int main(void) {
    // Disable stdout buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    minprintf("%d %f %s", 10, 20.5, "ishan khare");
    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap;
    int i_val;
    double d_val;
    char *p, *sval;

    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }

        switch(*++p) {
            case 'd':
                i_val = va_arg(ap, int);
                printf("%d", i_val);
                break;
            case 'f':
                d_val = va_arg(ap, double);
                printf("%.2f", d_val);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++){
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
            break;
        }
    }
    va_end(ap);
}
