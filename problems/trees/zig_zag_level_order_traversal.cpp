#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertNodeAtLevel( map<int,vector<TreeNode*>>& levelNodeMap, TreeNode* A, int level ){
    if( A == NULL )
        return;

    auto it = levelNodeMap.find( level );
    if( it != levelNodeMap.end() ){
        it->second.push_back( A );
    } else {
        vector<TreeNode*> arr( 1, A );
        pair<int, vector<TreeNode*>> pair1( level, arr );
        levelNodeMap.insert( pair1 );
    }

    insertNodeAtLevel( levelNodeMap, A->left, level+1 );
    insertNodeAtLevel( levelNodeMap, A->right, level+1 );
}

vector<vector<int> > zigzagLevelOrder(TreeNode* A) {

    map<int,vector<TreeNode*>> levelNodeMap;
    insertNodeAtLevel( levelNodeMap, A, 0 );

    vector<vector<int>> ans;
    for( auto it = levelNodeMap.begin(); it != levelNodeMap.end(); it++ ){
        vector<int> ansOfLevel( it->second.size() );
        for( int i=0; i<it->second.size(); i++ ){
            ansOfLevel[i] = it->second[i]->val;
        }
        if( it->first % 2 == 1 ){
            reverse( ansOfLevel.begin(), ansOfLevel.end() );
        }
        ans.push_back( ansOfLevel );
    }
    return ans;
}

int main() {

    //
    return 0;
}