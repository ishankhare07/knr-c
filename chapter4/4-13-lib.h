#include <string.h>

void reverse(char s[]) {
    void reverser(char[], int, int);

    reverser(s, 0, strlen(s)-1);    // -1 for skipping '\0'
}

void reverser(char s[], int i, int length) {
    char temp;

    if(i < length) {
        // swap i and length indexes
        temp        = s[i];
        s[i]        = s[length];
        s[length]   = temp;

        reverser(s, ++i, --length);
    } else {
        return;
    }
}
