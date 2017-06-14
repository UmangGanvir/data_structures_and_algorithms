#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>

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
    map<Node*, list<pair<Node*,int>>> adj;    // each list has pair of ( pointer to node, weight )

    void addEdge( Node* u, Node* v, int weight );
    int edgeWeight( Node* u, Node* v);
    map<Node*,Node*> primMST();
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

int Graph::edgeWeight(Node *u, Node *v) {
    int weight = numeric_limits<int>::max();
    for( auto nodeAdjListIt = this->adj[u].begin(); nodeAdjListIt != this->adj[u].end(); nodeAdjListIt++ ){
        if( nodeAdjListIt->first == v )
            weight = nodeAdjListIt->second;
    }
    return weight;
}

Node* extractMinNodeKey( map<Node*, int>& nodeKey ){

    int min = numeric_limits<int>::max();

    for( auto it = nodeKey.begin(); it != nodeKey.end(); it++ ){
        if( it->second < min )
            min = it->second;
    }

    Node* minNode = NULL;
    for( auto it = nodeKey.begin(); it != nodeKey.end(); it++ ){
        if( it->second == min ){
            minNode = it->first;
        }
    }

    nodeKey.erase( nodeKey.find( minNode ) );
    return minNode;
}

map<Node*,Node*> Graph::primMST(){

    map<Node*,Node*> parent;
    map<Node*, int> nodeKey;
    set<Node*> mstSet;

    // Initialization
    for( auto adjListIt = this->adj.begin(); adjListIt != this->adj.end(); adjListIt++ ){
        if( adjListIt == this->adj.begin() ){
            pair<Node*, int> firstNodeKeyPair( adjListIt->first, 0 );
            nodeKey.insert( firstNodeKeyPair );                 // Set first Node's key value as 0
        } else {
            pair<Node*, int> otherNodeKeyPair( adjListIt->first, numeric_limits<int>::max() );
            nodeKey.insert( otherNodeKeyPair );                 // Set All Other Node keys value as Infinity
        }
    }

    while( mstSet.size() != this->V ){

        Node* minKeyNode = extractMinNodeKey( nodeKey );
        mstSet.insert( minKeyNode );

        for( auto nodeAdjListIt = this->adj[minKeyNode].begin(); nodeAdjListIt != this->adj[minKeyNode].end(); nodeAdjListIt++ ){
            Node* neighbouringNode = nodeAdjListIt->first;

            auto nodeKeyNeighbourIt = nodeKey.find( neighbouringNode );
            auto nodeKeyCurrNodeIt = nodeKey.find( minKeyNode );
            if( nodeKeyNeighbourIt->second > nodeKeyCurrNodeIt->second + this->edgeWeight( minKeyNode, neighbouringNode ) ){
                nodeKeyNeighbourIt->second = nodeKeyCurrNodeIt->second + this->edgeWeight( minKeyNode, neighbouringNode );

                pair<Node*,Node*> parentPair1( neighbouringNode, minKeyNode );
                parent.insert( parentPair1 );
            }
        }
    }

    return parent;
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

    map<Node*,Node*> parentsInMST = g.primMST();

    // printing Edges and Weights in prim's MST
    cout<<"Edge   Weight"<<endl;
    for( auto it = parentsInMST.begin(); it != parentsInMST.end(); it++ ){
        cout<<it->second->data<<" - "<<it->first->data<<"    "<<g.edgeWeight( it->first, it->second )<<endl;
    }

    return 0;
}