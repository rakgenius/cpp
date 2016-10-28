#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

class graph {
    int V;
    list<int> *adj;

    public:
    void add_edge(int u, int v);
    graph(int v);
    void topological_sort();
    void topologicalsortutil(int v, bool visited[], stack<int> &Stack);
};

graph::graph(int v)
{
    this->V = v;
    adj = new list<int>[V];
}

void graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
}

void graph::topologicalsortutil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (visited[*i] != true) {
            topologicalsortutil(*i, visited, Stack);
        }
    }

    Stack.push(v);

}

void graph::topological_sort()
{
    stack<int> Stack;
    bool *visited = new bool[V];

    int i = 0;

    for (i=0; i<V; i++)
        visited[i] = false;

    for (i=0; i<V; i++) {
        if (visited[i] != true) {
            topologicalsortutil(i, visited, Stack);
        }
    }

    while (Stack.empty() == false) {
        cout << Stack.top() << "\t";
        Stack.pop();
    }
}

int main()
{
    graph g(6);
    g.add_edge(0, 3);
    g.add_edge(0, 5);
    g.add_edge(1, 5);
    g.add_edge(1, 4);
    g.add_edge(3, 2);
    g.add_edge(2, 4);

    g.topological_sort();
    return 0;
}
