#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// This is brute force
// do not do this in real life
int main(int argc, char *argv[]) {
	treeptr root = create(50);
	printf("\n tree = ");
	preDisplay(root);
	setLeft(root,25);
	setRight(root,75);
	printf("\n tree = ");
	preDisplay(root);
	setLeft(getLeft(root),10);
	setRight(getLeft(root),40);
	setLeft(getRight(root),60);
	setRight(getRight(root),90);
	printf("\n tree = ");
	preDisplay(root);
	printf("\n tree = ");
	inDisplay(root);
	printf("\n\nRecursive");
	printf("\n Count v1= %d",countNodesV1(root));
	printf("\n Sum v1= %d", sumV1(root));
	printf("\n is there 40 v1: %d", containsV1(root,40));
	printf("\n is there 150 v1: %d", containsV1(root,150));
	printf("\n is there 90 v1: %d", containsV1(root,90));
	printf("\n is there 68 v1: %d", containsV1(root,60));
	
	
	printf("\n\nIterative - Stack");
	printf("\n Count v2= %d",countNodesV2(root));
	printf("\n Sum v2= %d",sumV2(root));
	printf("\n is there 40 v2: %d", containsV2(root,40));
	printf("\n is there 150 v2: %d", containsV2(root,150));
	
	printf("\n\nIterative - Queue");
	printf("\n Count v3= %d",countNodesV3(root));
	printf("\n Sum v3= %d",sumV3(root));
	printf("\n is there 40 v3: %d", containsV3(root,40));
	printf("\n is there 150 v3: %d", containsV3(root,150));
	
	
	printf("\n\nSmallest: %d", smallestV3(root));
	printf("\nSmallest: %d", smallestV1(root));
	
	printf("\n\n tree = ");
	preDisplay(root);
	printf("\n tree = ");
	inDisplay(root);
}
