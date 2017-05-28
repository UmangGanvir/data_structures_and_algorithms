#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LCSUtil( int idxA, string A, int idxB, string B, vector<vector<int>>& ans ){

    if( ans[idxA][idxB] != -1 )
        return ans[idxA][idxB];

    if( idxA == A.size() || idxB == B.size() ){
        ans[idxA][idxB] = 0;
        return ans[idxA][idxB];
    }

    int currAns = 0;
    if( A[idxA] == B[idxB] ){
        currAns = 1 + LCSUtil( idxA + 1, A, idxB + 1, B, ans );
    } else {
        currAns = max( LCSUtil( idxA + 1, A, idxB, B, ans ), LCSUtil( idxA, A, idxB + 1, B, ans ) );
    }

    ans[idxA][idxB] = currAns;
    return ans[idxA][idxB];
}

int longestCommonSubsequence( string A, string B ){

    if( A.size() == 0 || B.size() == 0 )
        return 0;

    vector<vector<int>> ans( A.size()+1, vector<int>(B.size()+1, -1) );
    return LCSUtil( 0, A, 0, B, ans );

}

int main() {

    string A = "ABCDGH";
    string B = "AEDFHR";
    cout<<"Ans: "<<longestCommonSubsequence( A, B )<<endl;

    return 0;
}