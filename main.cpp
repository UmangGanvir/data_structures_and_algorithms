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

int methodName( string A ){
    return 123;
}

int main() {

    string A = "Umang";
    cout<<"Ans: "<<methodName( A )<<endl;

    return 0;
}