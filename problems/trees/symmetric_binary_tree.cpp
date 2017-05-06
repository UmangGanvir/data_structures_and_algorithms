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

bool isSymmetricUtil( TreeNode* A, TreeNode* B ){

    if( A == NULL && B == NULL )
        return true;

    if( A != NULL && B == NULL )
        return false;

    if( A == NULL && B != NULL )
        return false;

    return isSymmetricUtil( A->left, B->right ) && isSymmetricUtil( A->right, B->left );
}

int isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if( A == NULL )
        return 1;

    if( A->left == NULL && A->right == NULL )
        return 1;

    if( A->left != NULL && A->right == NULL )
        return 0;

    if( A->right != NULL && A->left == NULL )
        return 0;

    return isSymmetricUtil( A->left, A->right ) ? 1 : 0;

}

int main() {

    //
    return 0;
}