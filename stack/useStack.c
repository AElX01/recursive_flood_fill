#include <stdio.h>
#include "Stack.h"


int main() {
    Stack s = stack_create();

    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_push(s, 4);
    stack_push(s, 5);

    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_pop(s));
}