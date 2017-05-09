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

vector<int> order(vector<int> &heights, vector<int> &infronts) {

    unsigned long n = heights.size();

    vector<pair<int,int>> infrontHeightPairs(n);
    for( int i=0; i<n; i++ ){
        pair<int,int> infrontHeightPair( infronts[i], heights[i] );
        infrontHeightPairs[i] = infrontHeightPair;
    }

    sort( infrontHeightPairs.begin(), infrontHeightPairs.end(), myFunc );

    vector<int> ans( n, -1 );
    for( int i=0; i<n; i++ ){

        // i'th height person's placement
        int iThEmptyPositionRequired = infrontHeightPairs[i].first;
        int selectedIdx = 0;

        while( iThEmptyPositionRequired > 0 || ans[selectedIdx] != -1 ){
            if( ans[selectedIdx] == -1 ){
                iThEmptyPositionRequired--;
            }
            selectedIdx++;
        }
        ans[selectedIdx] = infrontHeightPairs[i].second;
    }

    return ans;
}


int main() {

    vector<int> heights = { 5, 3, 2, 6, 1, 4 };
    vector<int> infronts = { 0, 1, 2, 0, 3, 2 };
    printIntVector( order( heights, infronts ) );
    return 0;
}