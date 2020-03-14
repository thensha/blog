#include <stdio.h>

void servant(void);

int main(void) {
    printf("Hello, my servant.\n");
    servant();
    printf("Yes, you are right.\n");

    return 0;
}

void servant(void) {
    printf("I am here, my lord.\n");
}
