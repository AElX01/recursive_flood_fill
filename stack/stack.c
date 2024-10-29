#include <stdlib.h>
#include "stack.h"


typedef struct strNode {
    Type Data;
    struct strNode *Prior;
} *Node;

struct strStack {
    Node top;
    unsigned size;
    void (*destroy_dataAtNode) (Type);
};

Stack stack(void (*destroy_dataAtNode) (Type)) {
    Stack s = (Stack) calloc(1, sizeof(struct strStack)); // INITIALIZES ALL IN 0 SO WE AVOID ASSIGNING THE INITIAL SIZE

    if (s) {
        s->destroy_dataAtNode = destroy_dataAtNode;
        return s;
    } else return NULL;
}

unsigned getSize(Stack s) {return s ? s->size : 0;}

boolean stack_isEmpty(Stack s) {return (s && s->size) ? FALSE : TRUE;}

Type getTop(Stack s) {return (s && !stack_isEmpty(s)) ? s->top->Data : NULL;}

void push(Stack s, Type t) {
    if (s) {
        Node newTop = (Node) calloc(1, sizeof(struct strNode));
        if (!newTop) return;

        newTop->Prior = s->top;
        newTop->Data = t;

        s->top = newTop; 
        s->size++;
    }
}

Type pop(Stack s) {
    if (s) {
        Node toReturn = s->top;
        Node newTop = s->top->Prior;

        free(s->top);
        s->top = newTop;
        s->size--;
        return toReturn->Data;
    }

    return NULL;
}

void stack_destroy(Stack s) {
    if (s) {
        Node current = s->top;
        Node next;

        while (current) {
            if (s->destroy_dataAtNode) s->destroy_dataAtNode(current->Data);
            next = current->Prior;
            free(current);
            current = next;
        }

        free(s);
    }
}
