#ifndef BINTREE_H
#define BINTREE_H

typedef int treeItem;
typedef struct tnode *treeptr;
struct tnode {
	treeItem item;
	treeptr parent;
	treeptr left;
	treeptr right;
};

treeptr create(treeItem item);
void setLeft(treeptr p,treeItem item);
void setRight(treeptr p,treeItem item);
treeptr getRight(treeptr p);
treeptr getLeft(treeptr p);

int isLeft(treeptr p); // is p a left child
int isRight(treeptr p); // is p a left child
int isRoot(treeptr p);

void preDisplay(treeptr root);
void inDisplay(treeptr root);



// recursive
int countNodesV1(treeptr root);
int sumV1(treeptr root);
int containsV1(treeptr root,treeItem item); // search, 1 if there, 0 if not

// iterative - Stack
int countNodesV2(treeptr root);
int sumV2(treeptr root);
int containsV2(treeptr root,treeItem item); // search, 1 if there, 0 if not

// iterative - Queue
int countNodesV3(treeptr root);
int sumV3(treeptr root);
int containsV3(treeptr root,treeItem item); // search, 1 if there, 0 if not


#endif
