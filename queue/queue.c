#include <stdlib.h>
#include "queue.h"


struct strQueue {
    char *arrQueue;
    int size, capacity;
};

Queue queue() {}
unsigned QueueSize(Queue) {}
char peek(Queue) {}
void offer(Queue, char) {}
char poll(Queue) {}
void queue_destroy(Queue) {}