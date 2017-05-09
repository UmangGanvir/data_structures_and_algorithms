#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

bool myFunc( pair<int,int> a, pair<int,int> b ){
    return a.second < b.second;
}

class SegmentTree {
public:
    int minIdx;
    int maxIdx;
    int filledElemsCount;
    SegmentTree* left;
    SegmentTree* right;

    SegmentTree( int minIdx1, int maxIdx1 ){
        this->minIdx = minIdx1;
        this->maxIdx = maxIdx1;
        this->filledElemsCount = 0;
    }
};

SegmentTree* initializeSegmentTree( SegmentTree* root, int minIdx, int maxIdx ){

    if( minIdx == maxIdx ){
        return new SegmentTree( minIdx, maxIdx );
    }

    root = new SegmentTree( minIdx, maxIdx );
    root->left = initializeSegmentTree( root->left, minIdx, minIdx + ( maxIdx - minIdx )/2 );
    root->right = initializeSegmentTree( root->right, minIdx + ( maxIdx - minIdx )/2 + 1, maxIdx );
    return root;
}

void setInsertStateInSegmentTree( SegmentTree* root, int idx ){

    /*
     * Insertion is represented by the filledElemsCount of the node with minIdx == maxIdx
     * */

    if( root == NULL )
        return;

    if( root->minIdx == root->maxIdx && root->minIdx == idx ){
        root->filledElemsCount++;
        return;
    }

    root->filledElemsCount++;

    if( idx <= root->minIdx + ( root->maxIdx - root->minIdx )/2 ){
        setInsertStateInSegmentTree( root->left, idx );
    } else {
        setInsertStateInSegmentTree( root->right, idx );
    }
}

int searchIthEmptyIdxInSegmentTree( SegmentTree* root, int iThEmptyPosition ){

    if( root->minIdx == root->maxIdx )
        return root->minIdx;

    if( root->left->maxIdx - root->left->minIdx + 1 - root->left->filledElemsCount > iThEmptyPosition ){
        return searchIthEmptyIdxInSegmentTree( root->left, iThEmptyPosition );
    } else {
        return searchIthEmptyIdxInSegmentTree(
                root->right,
                iThEmptyPosition - ( root->left->maxIdx - root->left->minIdx + 1 - root->left->filledElemsCount )
        );
    }
}

vector<int> order(vector<int> &heights, vector<int> &infronts) {

    unsigned long n = heights.size();

    vector<pair<int,int>> infrontHeightPairs(n);
    for( int i=0; i<n; i++ ){
        pair<int,int> infrontHeightPair( infronts[i], heights[i] );
        infrontHeightPairs[i] = infrontHeightPair;
    }

    sort( infrontHeightPairs.begin(), infrontHeightPairs.end(), myFunc );

    SegmentTree* root = NULL;
    root = initializeSegmentTree( root, 0, (int) (n - 1) );

    vector<int> ans( n, -1 );
    for( int i=0; i<n; i++ ){

        // i'th height person's placement
        int iThEmptyPositionRequired = infrontHeightPairs[i].first;
        int selectedIdx = searchIthEmptyIdxInSegmentTree( root, iThEmptyPositionRequired );
        setInsertStateInSegmentTree( root, selectedIdx );
        ans[selectedIdx] = infrontHeightPairs[i].second;
    }

    return ans;
}


int main() {

    vector<int> heights = { 5, 3, 2, 6, 1, 4 };
    vector<int> infronts = { 0, 1, 2, 0, 3, 2 };
    printIntVector( order( heights, infronts ) ); // 5 3 2 1 6 4
    return 0;
}