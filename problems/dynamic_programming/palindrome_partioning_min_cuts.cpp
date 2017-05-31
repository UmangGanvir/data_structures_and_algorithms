#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int minCutUtilDP(
        int startIdx, int endIdx, string A, vector<vector<bool>>& palindromeOrNotMap, vector<vector<int>>& DPStringByIndexesMap
){

    if( DPStringByIndexesMap[startIdx][endIdx] != A.size() )
        return DPStringByIndexesMap[startIdx][endIdx];

    if( palindromeOrNotMap[startIdx][endIdx] == true ){
        DPStringByIndexesMap[startIdx][endIdx] = 0;
        return 0;
    }

    int min = numeric_limits<int>::max();
    for( int i=startIdx; i<endIdx; i++ ){

        int currMinCutDP = 1;
        currMinCutDP += minCutUtilDP( startIdx, i, A, palindromeOrNotMap, DPStringByIndexesMap );
        currMinCutDP += minCutUtilDP( i+1, endIdx, A, palindromeOrNotMap, DPStringByIndexesMap );

        if( currMinCutDP < min )
            min = currMinCutDP;
    }
    DPStringByIndexesMap[startIdx][endIdx] = min;
    return min;
}

int minCut(string A) {

    unsigned long int n = A.size();

    vector<vector<bool>> palindromeOrNotMap( n, vector<bool>( n, false ) );

    for( int i=0; i<n; i++ )
        palindromeOrNotMap[i][i] = true;

    for( int size=2; size <= n; size++ ){
        for( int startIdx=0; startIdx < n-size+1; startIdx++ ){
            int endIdx = startIdx + size -1;

            if( size == 2 )
                palindromeOrNotMap[startIdx][endIdx] = ( A[startIdx] == A[endIdx] );
            else
                palindromeOrNotMap[startIdx][endIdx] = ( A[startIdx] == A[endIdx] ) && palindromeOrNotMap[startIdx+1][endIdx-1];
        }
    }

    vector<vector<int>> DPStringByIndexesMap( n, vector<int>(n, (const int &) n) );
    return minCutUtilDP(0, (int) (n - 1), A, palindromeOrNotMap, DPStringByIndexesMap );
}

int main() {

    string A = "ababbbabbababa"; // => a | babbbab | b | ababa ---> total = 3
    cout<<"Ans: "<<minCut( A )<<endl;

    string B = "dVGAaVO25EmT6W3zSTEA0k12i64Kkmmli09Kb4fArlF4Gc2PknrlkevhROxUg"; // 59 -> TLE Case
    cout<<"Ans: "<<minCut( B )<<endl;

    return 0;
}