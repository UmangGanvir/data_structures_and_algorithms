#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    int level;
    Node* parent;

    Node( int v ){
        this->val = v;
        this->level = -1;
    }
};

class Graph {
public:
    int V;
    list<Node*> *adj;

    Graph(int v1);
    void addEdge( Node* v, Node* w );
    void BFS( Node* s );
};

Graph::Graph(int v1) {
    this->V = v1;
    this->adj = new list<Node*> [v1];
}

void Graph::addEdge(Node* v, Node* w) {
    this->adj[ (*v).val ].push_back( w );
}

void Graph::BFS(Node* s) {

    queue<Node*> q1;
    int currLevel = 0;

    (*s).level = currLevel;
    q1.push( s );

    while( !q1.empty() ){

        Node currElem = *(q1.front());
        cout<<"val: "<<currElem.val<<" - level: "<<currElem.level<<endl;
        q1.pop();

        for( list<Node*>::iterator it = this->adj[ currElem.val ].begin(); it != this->adj[ currElem.val ].end(); it++ ){

//            cout<<"val---: "<<(*it)->val<<" - level---: "<<(*it)->level<<endl;
            if( (*it)->level == -1 ){
                (*it)->parent = &currElem;
                (*it)->level = (*it)->parent->level + 1;
                q1.push( *it );
            }
//            cout<<"val+++: "<<(*it)->val<<" - level+++: "<<(*it)->level<<endl;
        }
    }

}

int main() {

    Graph g(4);
    Node* a0 = new Node(0);
    Node* a1 = new Node(1);
    Node* a2 = new Node(2);
    Node* a3 = new Node(3);

    g.addEdge(a0, a1);
    g.addEdge(a0, a2);
    g.addEdge(a1, a2);
    g.addEdge(a2, a0);
    g.addEdge(a2, a3);
    g.addEdge(a3, a3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS( a2 );

    return 0;
}