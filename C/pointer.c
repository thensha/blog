#include <stdio.h>

void changeByPointer(int * num);
void changeByValue(int num);

int main(void) {
    int someInt;

    someInt = 1;

    printf("someInt originally is: %d\n", someInt);

    changeByPointer(&someInt);
    changeByValue(someInt);

    printf("someInt changed: %d\n", someInt);

    return 0;
}

void changeByPointer(int * num) {
    *num = 2;
}

void changeByValue(int num){

    num = 3;
    printf("changeByValue parameter is: %d\n", num);
}

//someInt originally is: 1
//changeByValue parameter is: 3
//someInt changed: 2
