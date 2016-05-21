#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
using namespace std;

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} Tnode;

Tnode* getNode(int data)
{
	Tnode *node = (struct treenode *)malloc(sizeof(struct treenode *));
	node->data = data;
	node->left=node->right=NULL;
	return node;
}
	
int main()
{
	Tnode *mynode = getNode(10);
	return 0;
}
