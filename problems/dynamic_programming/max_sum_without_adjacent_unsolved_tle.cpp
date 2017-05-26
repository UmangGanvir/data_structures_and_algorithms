#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int DP( int colIdx, vector<vector<int>>& A, unordered_map<int, int>& colIdxMaxMap ){

    auto it = colIdxMaxMap.find( colIdx );
    if( it != colIdxMaxMap.end() ){
        return it->second;
    }

    if( colIdx >= A[0].size() ){
        pair<int,int> pair1( colIdx, 0 );
        colIdxMaxMap.insert( pair1 );
        return 0;
    }

    int nextMax = 0;
    for( int i=colIdx+2; i < A[0].size(); i++ ){

        int currMaxForNext = DP( i, A, colIdxMaxMap );

        if( currMaxForNext > nextMax ){
            nextMax = currMaxForNext;
        }
    }

    int maxIncludingCurrElem = max( A[0][colIdx], A[1][colIdx] ) + nextMax;
    pair<int,int> pair3( colIdx, maxIncludingCurrElem );
    colIdxMaxMap.insert( pair3 );

    return maxIncludingCurrElem;
}

int adjacent(vector<vector<int> > &A) {

    unordered_map<int, int> colIdxMaxMap;
    return max( DP( 0, A, colIdxMaxMap ), DP( 1, A, colIdxMaxMap ));
}

int main() {

    vector<vector<int>> A = {
            { 1, 2, 3, 4 },
            { 2, 3, 4, 5 }
    };

    /*
     * Unsolved!
     * TLE for this problem!
     * */

    cout<<"Ans: "<<adjacent( A )<<endl;
    return 0;
};