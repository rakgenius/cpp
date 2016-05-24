#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 26

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct trieNode {
    bool isLeaf;
    struct trieNode *children[SIZE];
};

struct trieNode *getNode(void)
{
    struct trieNode *node;
    int i;

    node = (struct trieNode *)malloc(sizeof(struct trieNode));

    for (i=0;i<SIZE;i++) {
        node->children[i] = NULL;
    }

    node->isLeaf = false;
    return node;
}

void insert(struct trieNode *root, char *key)
{
    int i;
    int length = strlen(key);
    int index;

    struct trieNode *tmp = root;

    for (i=0; i<length; i++) {
        index = CHAR_TO_INDEX(key[i]);
        if (!tmp->children[index]) {
            tmp->children[index] = getNode();
        } else {
            tmp = tmp->children[index];
        }
    }

    tmp->isLeaf = true;
}

int search(struct trieNode *root, const char *key)
{
    struct trieNode *tmp = root;
    int i;
    int index;
    int length = strlen(key);

    for (i=0;i<length; i++)
    {
        index = CHAR_TO_INDEX(key[i]);
        if (!tmp->children[index])
            return 0;

        tmp = tmp->children[index];
    }

    return (tmp != NULL && tmp->isLeaf == true);
}

int main()
{
    char keys[][14] = {
        "Rakesh",
        "Pooja",
        "Malini",
        "Venkatesh"
    };

    char output [][32] = {
        "Not present",
        "Present in the trie"
    };

    struct trieNode *root = getNode();

    int i;

    for (i=0; i< sizeof(keys)/sizeof(keys[0]); i++)
        insert(root, keys[i]);

    return 0;
}
