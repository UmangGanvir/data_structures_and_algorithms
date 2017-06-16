#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    cout<<"Printing vector of int vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

vector<vector<int> > levelOrder(TreeNode* A) {

    unordered_map<TreeNode*, int> nodeLevelMap;
    vector<vector<int>> ans;

    queue<TreeNode*> q1;

    // Initialization
    pair<TreeNode*, int> pairRoot( A, 0 );
    nodeLevelMap.insert( pairRoot );

    q1.push( A );

    while( !q1.empty() ){

        TreeNode* currNode = q1.front();
        q1.pop();

        // Process Current Node

        auto levelIt = nodeLevelMap.find( currNode );
        int currLevel = levelIt->second;
        if( currLevel + 1 > ans.size() ){
            vector<int> levelArr( 1, currNode->val );
            ans.push_back( levelArr );
        } else {
            ans[ currLevel ].push_back( currNode->val );
        }

        if( currNode->left != NULL ){
            q1.push( currNode->left );
            pair<TreeNode*, int> leftNodePair( currNode->left, currLevel + 1 );
            nodeLevelMap.insert( leftNodePair );
        }

        if( currNode->right != NULL ){
            q1.push( currNode->right );
            pair<TreeNode*, int> rightNodePair( currNode->right, currLevel + 1 );
            nodeLevelMap.insert( rightNodePair );
        }
    }

    return ans;
}

int main() {

    TreeNode* root = new TreeNode(1);
    printVectorOfVectorInt( levelOrder( root ));

    return 0;
}