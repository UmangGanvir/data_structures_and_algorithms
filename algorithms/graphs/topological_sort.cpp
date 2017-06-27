#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    vector<list<int>> adj;

    Graph( int v );
    void addEdge( int u, int v );
    void topologicalSortUtil( int u, vector<bool>& visited, stack<int>& stack1 );
    void topologicalSort();
};

Graph::Graph(int v) {
    this->V = v;
    vector<list<int>> adj( v, list<int>(0) );
    this->adj = adj;
}

void Graph::addEdge(int u, int v) {
    this->adj[u].push_back( v );
}

void Graph::topologicalSortUtil(int u, vector<bool> &visited, stack<int> &stack1) {

    visited[u] = true;

    for( auto it = this->adj[u].begin(); it != this->adj[u].end(); it++ ){
        if( !visited[ *it ] ){
            this->topologicalSortUtil( *it, visited, stack1 );
        }
    }

    stack1.push( u );
}

void Graph::topologicalSort() {

    int n = this->V;

    vector<bool> visited( n, false );
    stack<int> stack1;

    for( int i=0; i<n; i++ ){
        if( !visited[i] ){
            this->topologicalSortUtil( i, visited, stack1 );
        }
    }

    while( !stack1.empty() ){
        cout<<stack1.top()<<" ";
        stack1.pop();
    }
}

int main() {

    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}