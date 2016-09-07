/*
 * =====================================================================================
 *
 *       Filename:  btreetoClist.cc
 *
 *    Description:  Program to convert binary tree to circulat doubly linked list
 *
 *        Version:  1.0
 *        Created:  09/07/2016 15:45:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh Venkatesh
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

Node *newnode(int x)
{
	Node *tmp = new Node();
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

Node *concatenate(Node *leftnode, Node *rightnode)
{
	if (leftnode == NULL)
		return rightnode;

	if (rightnode == NULL)
		return leftnode;

	Node *leftlast = leftnode->left;
	Node *rightlast = rightnode->left;

	leftlast->right = rightnode;
	rightnode->left = leftlast;
	rightlast->right = leftnode;
	leftnode->left = rightlast;

	return leftnode;
}

Node *btreetoClist(Node *node)
{
	if (node == NULL)
		return NULL;

	Node *leftnode = btreetoClist(node->left);
	Node *rightnode = btreetoClist(node->right);

	node->right = node->left = node;

	return concatenate(concatenate(leftnode, node), rightnode);
}

void displaylist(Node *node)
{
	Node *tmp = node;

	do {
		cout << tmp->data  << "\t";
		tmp = tmp->right;
	} while (tmp != node);
	cout <<endl;
}
int main()
{
	Node *root = newnode(10);
	root->left = newnode(12);
	root->right = newnode(15);
	root->left->left = newnode(25);
	root->left->right = newnode(30);
	root->right->left = newnode(36);

	Node *head = btreetoClist(root);

	displaylist(head);

}
