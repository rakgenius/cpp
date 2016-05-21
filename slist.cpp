#include<iostream>
#include "slist.h"
using namespace std;

slist::~slist() {
    for (slistNode *tmp; !isEmpty();) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

void slist::displayList() {
    if (!isEmpty()) {
        slistNode *tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
}

void slist::addToHead(int x) {
    slistNode *tmp = new slistNode(x);
    if (head == NULL) {
        head = tail = tmp;
    } else {
        tmp->next = head;
        head = tmp;
    }
}

void slist::addToTail(int x) {
    slistNode *tmp = new slistNode(x);
    if (tail == NULL) {
        head = tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}

int slist::deleteFromHead() {
    int x = head->data;
    if (head == NULL) {
        cout <<"Linked list is empty. Unable to delete\n" <<endl;
        return -1;
    } else {
        slistNode *tmp = head->next;
        delete head;
        head = tmp;
    }

    if (head == tail) {
        head = tail = NULL;
    }
    return x;
}

int slist::deleteFromTail() {
    int x;
    slistNode *tmp = head;

    if (head == tail) {
        x = head->data;
        delete head;
        head = tail = NULL;
    } else {
        while (tmp->next != tail) {
            tmp = tmp->next;
        }

        x = tail->data;
        delete tail;
        tail = tmp;
    }
    return x;
}

void slist::deleteNode(int x) {
    slistNode *tmp, *tmp1;

    //base case if list is null
    if (head == NULL) {
        cout << "Linked list is null" << endl;
        return;
    }

    //if only one node exists
    if ((head == tail) && (head->data == x)){
        delete head;
        head = tail = NULL;
    }

    if (head->data == x) {
        tmp = head->next;
        delete head;
        head = tmp;
    } else {
        for (tmp = head, tmp1=head->next; tmp1!=NULL && tmp1->data != x; tmp=tmp->next, tmp1=tmp1->next);

        if (tmp1 != NULL) {
            tmp->next = tmp1->next;
            if (tmp1 == tail) {
                tail = tmp;
            }

            delete tmp1;
        }
    }
}

int main()
{
    slist *list = new slist();
    list->addToTail(1);
    list->addToTail(2);
    list->addToTail(3);
    list->addToTail(4);
    list->addToTail(5);

    list->displayList();
    return 0;
}
