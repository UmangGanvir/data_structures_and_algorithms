#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findDepth( int val, TreeNode* root, int currDepth, vector<int>& path ){

    if( root == NULL )
        return -1;

    if( root->val == val ){
        path.push_back( val );
        return currDepth;
    }

    int depthLeft = findDepth( val, root->left, currDepth+1, path );
    if( depthLeft != -1 )
        path.push_back( root->val );

    int depthRight = findDepth( val, root->right, currDepth+1, path );
    if( depthRight != -1 )
        path.push_back( root->val );

    return max( depthLeft, depthRight );
}

int lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> path1;
    int depth1 = findDepth( val1, A, 0, path1 );
    reverse( path1.begin(), path1.end() );

    vector<int> path2;
    int depth2 = findDepth( val2, A, 0, path2 );
    reverse( path2.begin(), path2.end() );

//    cout<<"depth1: "<<depth1<<endl;
//    cout<<"depth2: "<<depth2<<endl;

    if( depth1 == -1 || depth2 == -1 )
        return -1;

    int ans = -1;
    for( int i=0; i<min( depth1, depth2 )+1; i++ ){
        if( path1[i] == path2[i] )
            ans = path1[i];
        else
            break;
    }
    return ans;
}

int main() {

    TreeNode* root = new TreeNode(1);
    cout<<lca( root, 1, 1 );
    return 0;
}