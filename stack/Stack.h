#ifndef STACK_H_
#define STACK_H_

typedef struct strStack * Stack;

Stack stack_create();
int stack_size(Stack);
char stack_top(Stack);
void stack_push(Stack, char);
char stack_pop(Stack);
void stack_destroy(Stack);

#endif