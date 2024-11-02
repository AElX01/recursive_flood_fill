#ifndef QUEUE_H_
#define QUEUE_H_


typedef struct strQueue *Queue;

Queue queue();
unsigned QueueSize(Queue);
char peek(Queue);
void offer(Queue, char);
char poll(Queue);
void queue_destroy(Queue);

#endif