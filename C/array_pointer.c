#include <stdio.h>

#define SIZE 5

void show_array(const double arr[], int n);
void multi_array(double arr[], int n, double mult);

int main(void) {
    double dip[SIZE] = {1, 2, 3, 4.21, 5.6};

    printf("The original array is: \n");
    show_array(dip, SIZE);
    multi_array(dip, SIZE, 2.5);

    printf("The multi_array is: \n");
    show_array(dip, SIZE);

    return 0;
}

void show_array(const double arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%8.3f", arr[i]);
    }

    putchar('\n');
}

void multi_array(double arr[], int n, double mult) {
    int i;

    for (i = 0; i < n; i++) {
        arr[i] *= mult;
    }
}
