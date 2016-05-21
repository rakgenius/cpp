#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class slistNode {
    public:
        slistNode() {
            next = NULL;
        }

        slistNode(int x) {
            data = x;
        }

        int data;
        slistNode *next;
};

class slist {
    public:
        slist() {
            head = tail = NULL;
        }

        ~slist();

        int isEmpty() {
            return head == NULL;
        }

        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int);
        bool isInList(int) const;
        void displayList();
        slistNode *head, *tail;
};

#endif
