/*
 * =====================================================================================
 *
 *       Filename:  dlist.cpp
 *
 *    Description:  Actual implementation of double linked list
 *
 *        Version:  1.0
 *        Created:  07/04/2016 17:56:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rakesh venaktesh
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "dlist.h"
using namespace std;

dlist::~dlist()
{
	for(dlistNode *tmp; !isEmpty();) {
		tmp = head;
		delete head;
		head = tmp;
	}
}

bool dlist::isEmpty()
{
	return (head == NULL);
}

void dlist::addToHead(int x)
{
	dlistNode *tmp = new dlistNode(x);
	if (head == NULL) {
		head = tail = tmp;
	} else {
		tmp->next = head;
		head = tmp;
	}
}

void dlist::addToTail(int x)
{
	dlistNode *tmp = new dlistNode(x);
	if (isEmpty()) {
		head = tail = tmp;
	} else {
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
}

void dlist::displayList()
{
	dlistNode *tmp = head;

	while (tmp != NULL) {
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}
