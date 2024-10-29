#include "../custom_dataTypes.h"

#ifndef STACK_H_
#define STACK_H_

typedef struct strStack *Stack;

Stack stack(void (*destroy_dataAtNode) (Type)); // IF THE STACK COULD NOT BE CREATED, RETURNS NULL
unsigned getSize();
boolean stack_isEmpty(Stack);
Type getTop(Stack);
void push(Stack, Type);
Type pop(Stack);
void stack_destroy(Stack);

#endif