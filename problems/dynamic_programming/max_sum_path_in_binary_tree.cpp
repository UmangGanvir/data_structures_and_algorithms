#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDownwardPath( TreeNode* root, unordered_map<TreeNode*, int>& maxDownwardPathMap ){

    auto it = maxDownwardPathMap.find( root );
    if( it != maxDownwardPathMap.end() )
        return it->second;

    if( root == NULL )
        return 0;

    int maxDownwardPathForNode = root->val + max( maxDownwardPath( root->left, maxDownwardPathMap ), maxDownwardPath( root->right, maxDownwardPathMap ) );
    pair<TreeNode*,int> pair1( root, maxDownwardPathForNode );
    maxDownwardPathMap.insert( pair1 );
    return maxDownwardPathForNode;
}

void findMaxSumPathUtil( TreeNode* root, int& maxSum, unordered_map<TreeNode*, int>& maxDownwardPathMap ){

    if( root == NULL )
        return;

    int leftMaxDownwardPath = maxDownwardPath( root->left, maxDownwardPathMap );
    int rightMaxDownwardPath = maxDownwardPath( root->right, maxDownwardPathMap );
    int maxSumPathCrossingThisNode = root->val;
    if( leftMaxDownwardPath > 0 )
        maxSumPathCrossingThisNode += leftMaxDownwardPath;
    if( rightMaxDownwardPath > 0 )
        maxSumPathCrossingThisNode += rightMaxDownwardPath;

    if( maxSumPathCrossingThisNode > maxSum )
        maxSum = maxSumPathCrossingThisNode;

    findMaxSumPathUtil( root->left, maxSum, maxDownwardPathMap );
    findMaxSumPathUtil( root->right, maxSum, maxDownwardPathMap );
}


int maxPathSum(TreeNode* A) {

    unordered_map<TreeNode*, int> maxDownwardPathMap;
    int maxSum = numeric_limits<int>::min();
    findMaxSumPathUtil( A, maxSum, maxDownwardPathMap );
    return maxSum;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<"Ans: "<<maxPathSum( root )<<endl;

    return 0;
}