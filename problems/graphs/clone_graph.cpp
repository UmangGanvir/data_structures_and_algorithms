#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
   int label;
   vector<UndirectedGraphNode *> neighbors;
   UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* cloneGraphUtil( UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& oldNodeToNewNodeMap ){

    auto newNowExistenceIt = oldNodeToNewNodeMap.find( node );
    if( newNowExistenceIt != oldNodeToNewNodeMap.end() )
        return newNowExistenceIt->second;

    UndirectedGraphNode* newNode = new UndirectedGraphNode( node->label );
    pair<UndirectedGraphNode*, UndirectedGraphNode*> pair1( node, newNode );
    oldNodeToNewNodeMap.insert( pair1 );

    for( int i=0; i<node->neighbors.size(); i++ ){
        newNode->neighbors.push_back( cloneGraphUtil( node->neighbors[i], oldNodeToNewNodeMap ) );
    }
    return newNode;
}

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> oldNodeToNewNodeMap;
    return cloneGraphUtil( node, oldNodeToNewNodeMap );
}

int main() {


    return 0;
}