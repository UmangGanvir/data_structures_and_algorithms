#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int height( int nodeNum, unordered_map<int, int>& nodeHeightMap, vector<int>& A ){

    auto it = nodeHeightMap.find( nodeNum );
    if( it != nodeHeightMap.end() )
        return it->second;

    unsigned long int n = A.size();

    int maxHeight = 0;
    for( int i=0; i<n; i++ ){
        if( A[i] == nodeNum ){

            maxHeight = max( 1 + height( i, nodeHeightMap, A ), maxHeight );
        }
    }

    pair<int, int> pair1( nodeNum, maxHeight );
    nodeHeightMap.insert( pair1 );
    return maxHeight;
}

int diameter( int nodeNum, unordered_map<int, int>& nodeHeightMap, unordered_map<int, int>& nodeDiameterMap, vector<int>& A ){

    auto it = nodeDiameterMap.find( nodeNum );
    if( it != nodeDiameterMap.end() )
        return it->second;

    unsigned long int n = A.size();

    priority_queue<int> heights;
    int maxDiameter = 0;

    int numbOfChildren = 0;

    for( int i=0; i<n; i++ ){
        if( A[i] == nodeNum ){

            // Edge from A[i] to i ( undirected though )
            heights.push( height( i, nodeHeightMap, A ) );
            maxDiameter = max( diameter( i, nodeHeightMap, nodeDiameterMap, A ), maxDiameter );
            numbOfChildren++;
        }
    }

    if( numbOfChildren == 0 ){
        pair<int,int> pair1( nodeNum, 0 );
        nodeDiameterMap.insert( pair1 );
        return 0;
    }

    int highestSubtreeHeight = heights.top();
    heights.pop();

    if( heights.size() == 0 ){
        int ans = max( 1 + highestSubtreeHeight, maxDiameter );
        pair<int,int> pair1( nodeNum, ans );
        nodeDiameterMap.insert( pair1 );
        return ans;
    }

    int secondHighestSubtreeHeight = 0;
    secondHighestSubtreeHeight = heights.top();

    int ans = max( 2+highestSubtreeHeight+secondHighestSubtreeHeight, maxDiameter );
    pair<int,int> pair1( nodeNum, ans );
    nodeDiameterMap.insert( pair1 );
    return ans;
}

int solve(vector<int> &A) {

    unordered_map<int, int> nodeHeightMap;
    unordered_map<int, int> nodeDiameterMap;

    return diameter( 0, nodeHeightMap, nodeDiameterMap, A );
}

int main() {

    vector<int> A = { -1, 0, 0, 0, 3 };
    cout<<"Ans: "<<solve( A )<<endl;          // 3

    vector<int> B = { -1, 0 };
    cout<<"Ans: "<<solve( B )<<endl;          // 1

    vector<int> C = { -1, 0, 1, 1, 3, 2, 4, 6, 7, 8, 5, 8, 6, 9, 10, 9, 13, 2, 12, 17, 4, 17, 12, 11, 3, 15, 23, 19, 15, 27, 22, 26, 21, 24, 21, 32, 14, 34, 35, 25, 10, 35, 25, 16, 28, 40, 33, 40, 24, 46, 49, 37, 11, 30, 29, 50, 41, 7, 39, 54, 59, 55, 36, 61, 50, 18, 53, 43, 22, 57, 30, 44, 56, 19, 28, 29, 46, 51, 34, 53, 72, 38, 67, 43, 72, 26, 23, 48, 77, 88, 69, 31, 78, 49, 73, 91, 75, 65, 74, 62 };
    cout<<"Ans: "<<solve( C )<<endl;            // 20

    return 0;
}