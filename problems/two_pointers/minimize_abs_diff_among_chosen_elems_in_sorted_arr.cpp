#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int min_diff = numeric_limits<int>::max();

    int aMinIdx = 0;
    int bMinIdx = 0;
    int cMinIdx = 0;

    while( aMinIdx < A.size() && bMinIdx < B.size() && cMinIdx < C.size() ){


        min_diff = min( min_diff, abs(
                max( A[aMinIdx], max( B[bMinIdx], C[cMinIdx] ) ) - min( A[aMinIdx], min( B[bMinIdx], C[cMinIdx] ) )
        ));

        int curr_min = min( A[aMinIdx], min( B[bMinIdx], C[cMinIdx] ) );
        if( curr_min == A[aMinIdx] ){
            aMinIdx++;
        } else if( curr_min == B[bMinIdx] ){
            bMinIdx++;
        } else {
            cMinIdx++;
        }

    }
    return min_diff;
}

int main() {

    vector<int> A = { 1, 4, 5, 8, 10 };
    vector<int> B = { 6, 9, 15 };
    vector<int> C = { 2, 3, 6, 6 };
    cout<<"Min Difference: "<<solve( A, B, C )<<endl;

    return 0;
}