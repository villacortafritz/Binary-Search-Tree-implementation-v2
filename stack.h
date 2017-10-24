#ifndef STACK_H
#define STACK_H
#include "BinTree.h"

typedef enum {false, true} boolean;
typedef treeptr stackItem;
typedef struct stack *stackptr;
struct stack {
	stackItem item;
	stackptr next;
};
typedef stackptr Stack;

void push(Stack s,stackItem item);
void pop(Stack s);
stackItem peekv2(Stack s);
Stack newStack();
void destroyStack(Stack *s);
boolean isEmpty(Stack s);

#endif
