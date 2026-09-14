#include <stdio.h>

int stack_ex(){
    int a = 50;
    return a;
}

int main(){
    int a;
    int b = 5;
    int c = 1234;
    int *p = &b;

    a = stack_ex();

    printf("%d", a);

    return 0;
}