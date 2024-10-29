#include "../custom_dataTypes.h"

#ifndef QUEUE_H_
#define QUEUE_H_


typedef struct strQueue *Queue;

Queue queue(void (*destroy_dataAtNode) (Type));
unsigned getSize(Queue);
boolean queue_isEmpty(Queue);
Type peek(Queue);
void offer(Queue, Type);
Type poll(Queue);
void queue_destroy(Queue);

#endif