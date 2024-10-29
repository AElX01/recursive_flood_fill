#include <stdlib.h>
#include "queue.h"


typedef struct strNode {
    Type Data;
    struct strNode *next;
} *Node;

struct strQueue {
    Node first, last;
    unsigned size;
    void (*destroy_dataAtNode) (Type);
};

Queue queue(void (*destroy_dataAtNode) (Type)) {
    Queue q = (Queue) calloc(1, sizeof(struct strQueue));
    if (q) {
        q->destroy_dataAtNode = destroy_dataAtNode;
        return q;
    } else return NULL;
}

unsigned getSize(Queue q) {return q ? q->size : 0;}

boolean queue_isEmpty(Queue q) {return (q && q->size) ? FALSE : TRUE;}

Type peek(Queue q) {return (!queue_isEmpty(q)) ? q->first->Data : NULL;}

void offer(Queue q, Type t) {
    Node newLast = (Node) calloc(1, sizeof(struct strNode));

    if (q && newLast) {
        newLast->Data = t;
        if (!queue_isEmpty(q)) {
            q->last->next = newLast;
            q->last = newLast;
        } else {
            q->first = newLast;
        }

        q->size++;
    }
}

Type poll(Queue q) {
    if (q && q->size) {
        Type toReturn = q->first->Data;
        Node newFirst = q->first->next;
        free(q->first);

        q->first = newFirst;

        if (q->size == 1)
            q->last = NULL;
        q->size--;
        return toReturn;
    }

    return NULL;
}

void queue_destroy(Queue q) {
    if (q)
        return;
    
    Node current = q->first;

    while (current) {
        Node next = current->next;
        if (q->destroy_dataAtNode) q->destroy_dataAtNode(current->Data);
        free(current);
        current = next;
    }

    free(q);
}