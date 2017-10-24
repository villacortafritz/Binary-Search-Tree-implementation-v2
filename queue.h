#ifndef QUEUE_H
#define QUEUE_H
#include "BinTree.h"

typedef struct node *nodeptr;
typedef treeptr qItem;
struct node {
	qItem item;
	nodeptr next;	
};

struct queue {
	nodeptr front;
	nodeptr rear;
};

typedef struct queue *Queue;

Queue newQueue();
void destroyQueue(Queue *q);
void enqueue(Queue q,qItem item);
void dequeue(Queue q);
qItem peekv3(Queue q);
void display(Queue q);
boolean isEmptyv3(Queue q);

#endif
