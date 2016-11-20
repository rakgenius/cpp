#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node (int x)
        {
            data = x;
        }
};

void getvertical(Node *root, map <int, vector<int> > &hash, int hd)
{
    if (root == NULL)
        return;

    hash[hd].push_back(root->data);
    getvertical(root->left, hash, hd-1);
    getvertical(root->right, hash, hd+1);
}

void printvertical(Node *root)
{
    map <int, vector<int> > hash;
    int hd = 0;

    getvertical(root, hash, hd);

    map <int, vector<int> > :: iterator it;

    for (it = hash.begin(); it != hash.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    Node *d = new Node(5);
    Node *e = new Node(6);
    Node *f = new Node(7);
    Node *g = new Node(8);
    Node *h = new Node(9);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    e->right = g;
    e->left = NULL;
    f->right = h;
    f->left = NULL;

    printvertical(root);
    return 0;
}

