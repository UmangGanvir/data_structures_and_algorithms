#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int V;                          // vertices
    vector<list<int>> adj;          // adjacency list
    void DFSUtil( int s, vector<bool>& visited );

public:
    Graph(int V);
    void addEdge( int u, int v );
    void BFS( int s );
    void DFS( int s );
};

Graph::Graph( int V ){
    this->V = V;
    vector<list<int>> adj((unsigned long) V, list<int>(0) );
    this->adj = adj;
}

void Graph::addEdge(int u, int v) {
    this->adj[u].push_back( v );
}

void Graph::BFS(int s) {

    vector<bool> visited((unsigned long) this->V, false );

    queue<int> queue1;
    queue1.push( s );

    while( !queue1.empty() ){

        // mark current node as visited
        int currNode = queue1.front();
        cout<<currNode<<" ";
        visited[ currNode ] = true;
        queue1.pop();

        for( auto it = this->adj[currNode].begin(); it != this->adj[currNode].end(); it++ ){

            if( !visited[*it] ){
                queue1.push( *it );
            }
        }
    }

}

void Graph::DFS(int s) {
    vector<bool> visited((unsigned long) this->V, false );
    DFSUtil( s, visited );
}

void Graph::DFSUtil(int s, vector<bool> &visited) {

    if( visited[s] )
        return;

    // mark current node as visited
    int currentNode = s;
    cout<<currentNode<<" ";
    visited[currentNode] = true;

    for( auto it = this->adj[s].begin(); it != this->adj[s].end(); it++ ){
        if( !visited[ *it ] ){
            DFSUtil( *it, visited );
        }
    }
}

int main() {

    Graph g(4);
    g.addEdge( 0, 1 );
    g.addEdge( 0, 2 );
    g.addEdge( 1, 2 );
    g.addEdge( 2, 0 );
    g.addEdge( 2, 3 );
    g.addEdge( 3, 3 );

    cout<<"BFS: ";
    g.BFS( 2 );
    cout<<endl;

    cout<<"DFS: ";
    g.DFS( 2 );
    cout<<endl;

    return 0;
}