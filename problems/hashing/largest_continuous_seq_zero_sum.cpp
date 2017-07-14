#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

vector<int> lszero(vector<int> &A) {

    vector<int> sumTillElem( A.size(), 0 );
    {
        int currSumTillElem = 0;
        for( int i=0; i<A.size(); i++ ){
            currSumTillElem += A[i];
            sumTillElem[i] = currSumTillElem;
        }
    }

    int startIdx = -1, endIdx = -1;
    unordered_map<int,int> sumIdxMap;
    for( int i=0; i<A.size(); i++ ){

        if( sumTillElem[i] == 0 ){

            if( startIdx == -1 ){
                startIdx = 0;
                endIdx = i;
            } else if( i > endIdx - startIdx ){
                startIdx = 0;
                endIdx = i;
            }
            continue;
        }

        auto it = sumIdxMap.find( sumTillElem[i] );
        if( it != sumIdxMap.end() ){

            int currStartIdx = it->second + 1;
            int currEndIdx = i;

            if( startIdx == -1 ){
                startIdx = currStartIdx;
                endIdx = currEndIdx;
            } else if( currEndIdx - currStartIdx > endIdx - startIdx ){
                startIdx = currStartIdx;
                endIdx = currEndIdx;
            }

        } else {
            pair<int,int> pair1( sumTillElem[i], i );
            sumIdxMap.insert( pair1 );
        }
    }

    vector<int> ans;
    if( startIdx == -1 )
        return ans;

    for( int i=startIdx; i<=endIdx; i++ ){
        ans.push_back( A[i] );
    }
    return ans;
}

int main() {

    vector<int> A = { 1, 2, -2, 4, -4 };
    printIntVector( lszero( A ) );

    vector<int> B = { 1, 0, -1 };
    printIntVector( lszero( B ) );

    return 0;
}