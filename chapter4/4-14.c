#include <stdio.h>
#define swap(t, x, y) { \
            t _z = x;   \
            x = y;      \
            y = _z;     \
        }

int main() {
    int a = 10, b = 20;
    printf("a=> %d, b=> %d\n", a, b);
    swap(int, a, b);
    printf("a=> %d, b=> %d\n", a, b);

    return 0;
}
