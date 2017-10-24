#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT 10
#include "BinTree.h"
#include "stack.h"
#include "queue.h"

treeptr create(treeItem item) {
	treeptr t = (treeptr) malloc(sizeof(struct tnode));
	t->item = item;
	t->parent = t->left = t->right = NULL;
	return t;
}

treeptr getRight(treeptr p){
	return p->right;
}

treeptr getLeft(treeptr p) {
	return p->left;
}


void setLeft(treeptr p,treeItem item) {
	treeptr temp;
	if (p->left == NULL) {
		temp = create(item);
		p->left = temp;
		temp->parent = p;
	}	
}

void setRight(treeptr p,treeItem item) {
	treeptr temp;
	if (p->right == NULL) {
		temp = create(item);
		p->right = temp;
		temp->parent = p;
	}	
}

int isLeft(treeptr p){ // is p a left child
	int flag = 0; // false
	if (p->parent != NULL && p->parent->left == p) {
		flag = 1;
	}
	return flag;
}

int isRight(treeptr p){
	int flag = 0; // false
	if (p->parent != NULL && p->parent->right == p) {
		flag = 1;
	}
	return flag;
} // is p a left child

int isRoot(treeptr p){
	return p->parent == NULL;
}


/*
	traverse the left in preorder
	visit the root
	traverse the right in preorder
*/
void inDisplay(treeptr root) {
	if (root != NULL) {
		inDisplay(root->left);
		printf(" %d ",root->item);
		inDisplay(root->right);
	}		
}

/*
	visit the root
	traverse the left in preorder
	traverse the right in preorder
*/
void preDisplay(treeptr root) {
	if (root != NULL) {
		printf(" %d ",root->item);
		preDisplay(root->left);
		preDisplay(root->right);
	}		
}

// recursives
int smallestV1(treeptr root){
	if(root->left!=NULL){
		return smallestV1(root->left);	
	}
	else
		return root->item;
}
int countNodesV1(treeptr root) {
	return root==NULL? 0:1 + countNodesV1(root->left) + countNodesV1(root->right);	
	
}

int sumV1(treeptr root){
	return root==NULL? 0: root->item + sumV1(root->left) + sumV1(root->right);
}

int containsV1(treeptr root,treeItem item){
	return root==NULL?0: root->item==item? 1: containsV1(root->left,item) || containsV1(root->right,item);
/*	if(root == NULL){
		return 0;
	}
	else{
		if (root->item == item){
			return 1;
		}
		else{
			return containsV1(root->left,item) || containsV1(root->right,item);
		}
	}*/
	
}

// Stack Functions

stackptr createStackNode(stackItem x){
	stackptr p = (stackptr)malloc(sizeof(struct stack));
	p->item = x;
	p->next = NULL;
	
	return p;
}

Stack newStack(){
	Stack s = createStackNode('\0');
	return s;
}

void push(Stack s,stackItem item){
	stackptr temp = createStackNode(item);
	
	temp->next = s->next;
	s->next = temp;
}
void pop(Stack s){
	if(s->next!=NULL){
		stackptr p = s->next;
		s->next = p->next;
		free(p);
	}
}
stackItem peekv2(Stack s){
	if(s->next!=NULL){
		return s->next->item;
	}
}
boolean isEmpty(Stack s){
	return s->next == NULL? true:false;
}
void destroyStack(Stack *s){
	free(*s);
	*s = NULL;
}


// iterative - Stack


int countNodesV2(treeptr root){
	Stack s = newStack();
	treeptr p;
	int ctr = 0;
	push(s,root);
	while(!isEmpty(s)){
		p = peekv2(s);
		pop(s);
		ctr++;
		if(p->right!=NULL){
			push(s,p->right);
		}
		if(p->left!=NULL){
			push(s,p->left);
		}
	}
	destroyStack(&s);
	return ctr;
}

int sumV2(treeptr root){
	Stack s = newStack();
	treeptr p;
	int sum = 0;
	push(s,root);
	while(!isEmpty(s)){
		p = peekv2(s);
		pop(s);
		sum += p->item;
		if(p->right!=NULL){
			push(s,p->right);
		}
		if(p->left!=NULL){
			push(s,p->left);
		}
	}
	destroyStack(&s);
	return sum;
}
int containsV2(treeptr root,treeItem item){
	Stack s = newStack();
	treeptr p;
	int flag = 0;
	push(s,root);
	while(!isEmpty(s)){
		p = peekv2(s);
		pop(s);
		if(p->item == item){
			flag = 1;	
		}
		else{
			if(p->right!=NULL){
				push(s,p->right);
			}
			if(p->left!=NULL){
				push(s,p->left);
			}
		}
	}
	destroyStack(&s);
	return flag;
}

// Queue Functions

Queue newQueue() {
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;	
	return q;
}

void destroyQueue(Queue *q) {
	free(*q);
	*q=NULL;
}

void enqueue(Queue q,qItem item) {
	nodeptr p = (nodeptr)malloc(sizeof(struct node));
	p->item = item;
	p->next = NULL;
	if (q->rear == NULL) {
		q->front = p;
	} else {
		q->rear->next = p;
	}
	q->rear = p;	
}
void dequeue(Queue q) {
	nodeptr p;
	if (q->front != NULL) {
		p = q->front;
		q->front = p->next;
		free(p);
		if (q->front == NULL)		
			q->rear = NULL;		
	}
	
}

// not empty
qItem peekv3(Queue q) {
	return q->front->item;
}

void display(Queue q) {
	nodeptr p = q->front;
	printf("[");
	while (p!=NULL){
		printf(" %d",p->item);
		p = p->next;
	}
	printf("]");
}

boolean isEmptyv3(Queue q) {
	return (q->front == NULL);
}

// iterative - Queue

int countNodesV3(treeptr root){
	Queue q = newQueue();
	treeptr p;
	int ctr=0;
	enqueue(q,root);
	while(!isEmptyv3(q)){
		p = peekv3(q);
		dequeue(q);
		ctr++;
		if(p->right!=NULL){
			enqueue(q,p->right);
		}
		if(p->left!=NULL){
			enqueue(q,p->left);
		}
	}
	destroyQueue(&q);
	return ctr;
}
int sumV3(treeptr root){
	Queue q = newQueue();
	treeptr p;
	int sum=0;
	enqueue(q,root);
	while(!isEmptyv3(q)){
		p = peekv3(q);
		dequeue(q);
		sum += p->item;
		if(p->right!=NULL){
			enqueue(q,p->right);
		}
		if(p->left!=NULL){
			enqueue(q,p->left);
		}
	}
	destroyQueue(&q);
	return sum;
}
int containsV3(treeptr root,treeItem item){
	Queue q = newQueue();
	treeptr p;
	int flag = 0;
	enqueue(q,root);
	while(!isEmptyv3(q)){
		p = peekv3(q);
		dequeue(q);
		if(p->item == item){
			flag = 1;	
		}
		else{
			if(p->right!=NULL){
				enqueue(q,p->right);
			}
			if(p->left!=NULL){
				enqueue(q,p->left);
			}
		}
	}
	destroyQueue(&q);
	return flag;
}

int smallestV3(treeptr root){
	Queue q = newQueue();
	treeptr p;
	
	int small = 0;
	p = root->left;
	while(p->left!=NULL){
		p = p->left;	
		}
	
	return small = p->item;
}
