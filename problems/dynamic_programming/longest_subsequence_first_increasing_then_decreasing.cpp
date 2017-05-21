#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestSubsequenceLength( vector<int> A ){

    unsigned long int n = A.size();

    if( n < 2 )
        return (int) n;

    vector<int> longestIncreasingSubseqArr( n, 1 );

    for( int i=1; i<n; i++ ){
        for( int j=0; j<i; j++ ){

            if( A[j] < A[i] && longestIncreasingSubseqArr[i] < 1 + longestIncreasingSubseqArr[j] )
                longestIncreasingSubseqArr[i] = 1 + longestIncreasingSubseqArr[j];
        }
    }

    vector<int> longestDecreasingSubseqArr( n, 1 );
    for(int i= (int) (n - 2); i >= 0; i-- ){
        for( int j=i+1; j<n; j++ ){

            if( A[j] < A[i] && longestDecreasingSubseqArr[i] < 1 + longestDecreasingSubseqArr[j] )
                longestDecreasingSubseqArr[i] = 1 + longestDecreasingSubseqArr[j];
        }
    }

    int max = 0;
    for( int i=0; i<n; i++ ){
        if( longestIncreasingSubseqArr[i] + longestDecreasingSubseqArr[i] > max )
            max = longestIncreasingSubseqArr[i] + longestDecreasingSubseqArr[i];
    }
    return max-1;
}

int main() {

//    vector<int> A = { 1, 11, 2, 10, 4, 5, 2, 1 };
//    cout<<"longestSubsequenceLength: "<<longestSubsequenceLength( A )<<endl;    // 6

    vector<int> B = { 1, 3, 5, 6, 4, 8, 4, 3, 2, 1 };
    cout<<"longestSubsequenceLength: "<<longestSubsequenceLength( B )<<endl;    // 9

    return 0;
}