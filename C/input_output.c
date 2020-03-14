#include <stdio.h>

int main(void) {
    char msg;
    msg = getchar();

    while (msg != '\n') {
        putchar(msg);

        msg = getchar();
    }
    putchar(msg);

    return 0;
}
