/*
 * =====================================================================================
 *
 *       Filename:  btree.h
 *
 *    Description:  Header file to implement binary tree functions
 *
 *        Version:  1.0
 *        Created:  08/27/2016 19:23:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh Venkatesh
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __BTREE_H__
#define __BTREE_h__

#include <iostream>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

class Btree
{
	private:
		struct node *root;

	public:
		void insert(int item);
		bool isEmpty();
		bool isEmpty_tree(struct node *node);
		void Btree()
		{
			root = NULL;
		}
};

#endif
