/*
 * =====================================================================================
 *
 *       Filename:  dlist.h
 *
 *    Description:  Program to implement the double linked list
 *
 *
 *        Version:  1.0
 *        Created:  07/04/2016 17:50:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh venaktesh
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

class dlistNode {
	public:
		int data;
		dlistNode *next, *prev;

		dlistNode() {
			next = prev= NULL;
		}

		dlistNode(int x) {
			next = prev= NULL;
			data = x;
		}
};

class dlist {
	public:
		dlistNode *head, *tail;
		~dlist();
		void addToHead(int x);
		void addToTail(int x);
		void deleteFromHead();
		void deleteFromTail();
		void displayList();
		void deleteNode(int x);
		bool isInList(int x);
		bool isEmpty();
};

#endif
