#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestIncreasingSubsequence( vector<int> A ){

    long int n = A.size();

    vector<int> LISEndingAtIdxArr((unsigned long) n, 1 );

    for( int i=1; i<n; i++ ){
        for( int j=0; j<i; j++ ){

            if(
                A[j] < A[i] &&
                LISEndingAtIdxArr[i] < 1 + LISEndingAtIdxArr[j]
            )
                LISEndingAtIdxArr[i] = 1 + LISEndingAtIdxArr[j];

        }
    }

    int max = 0;
    for( int i=0; i<n; i++ ){
        if( LISEndingAtIdxArr[i] > max )
            max = LISEndingAtIdxArr[i];
    }

    return max;
}

int main() {

    vector<int> A = { 3, 10, 2, 1, 20 };
    cout<<"longestIncreasingSubsequence: "<<longestIncreasingSubsequence( A )<<endl;

    return 0;
}