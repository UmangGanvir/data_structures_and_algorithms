#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    Node* parent;

    Node( int data1 );
};

Node::Node(int data1) {
    this->data = data1;
}

class Graph {
public:
    int V;
    unordered_map<Node*, list<pair<Node*,int>>> adj;    // each list has pair of ( pointer to node, weight )

    void addEdge( Node* u, Node* v, int weight );
};

void Graph::addEdge(Node *u, Node *v, int weight) {
    auto it = this->adj.find( u );
    pair<Node*, int> pair1( v, weight );

    if( it != this->adj.end() ){

        it->second.push_back( pair1 );
    } else {

        this->V++;

        list<pair<Node*, int>> newList;
        newList.push_back( pair1 );
        pair<Node*, list<pair<Node*, int>>> pair2( u, newList );
        this->adj.insert( pair2 );
    }
}

int main() {

    Node* node0 = new Node(0);
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    Graph g;

    /*
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */

    g.addEdge( node0, node1, 2 );
    g.addEdge( node1, node0, 2 );

    g.addEdge( node1, node2, 3 );
    g.addEdge( node2, node1, 3 );

    g.addEdge( node0, node3, 6 );
    g.addEdge( node3, node0, 6 );

    g.addEdge( node1, node3, 8 );
    g.addEdge( node3, node1, 8 );

    g.addEdge( node1, node4, 5 );
    g.addEdge( node4, node1, 5 );

    g.addEdge( node2, node4, 7 );
    g.addEdge( node4, node2, 7 );

    g.addEdge( node3, node4, 9 );
    g.addEdge( node4, node3, 9 );

    return 0;
}