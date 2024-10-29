#ifndef QUEUE_H_
#define QUEUE_H_

typedef void *Type;
typedef struct strQueue *Queue;
typedef enum {FALSE, TRUE} boolean;

Queue queue(void (*destroy_dataAtNode) (Type));
unsigned getSize(Queue);
boolean queue_isEmpty(Queue);
Type peek(Queue);
void offer(Queue, Type);
Type poll(Queue);
void queue_destroy(Queue);

#endif