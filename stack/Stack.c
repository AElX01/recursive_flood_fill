#include <stdlib.h>
#include "Stack.h"

struct strStack {
    char *arrStack;
    int size, capacity;
};

Stack stack_create() {
    Stack s = (Stack) calloc(1, sizeof(struct strStack));

    s->capacity = 10;
    s->arrStack = (char*) calloc(s->capacity, sizeof(char));
    return s;
}

int stack_size(Stack s) { return s ? s->size : -1; }

char stack_top(Stack s) {
    if (s && s->size) return s->arrStack[s->size - 1];
    return -1;
}

void stack_push(Stack s, char t) {
    if (s) {
        if (!s->size) {
            s->arrStack[s->size] = t;
        } else if (s->capacity - s->size) {
            s->arrStack[s->size] = t;
        } else {
            char *newStack = (char*) realloc(s->arrStack, (2 * s->capacity));
            s->arrStack = newStack;
            s->capacity *= 2;
            s->arrStack[s->size] = t;
        }

        s->size++;
    }
}

char stack_pop(Stack s) {
    if (s) {
        if (s->size >= 0) {
            char dataToReturn = s->arrStack[s->size - 1];
            s->size--;
            return dataToReturn;
        }
    } 

    return -1;
}

void stack_destroy(Stack s) {
    free(s->arrStack);
    free(s);
}