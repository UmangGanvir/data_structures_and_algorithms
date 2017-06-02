#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxProfit( const vector<int> &A ){

    unsigned long int n = A.size();

    if( n < 2 )
        return 0;

    int minimaIdx = 0;
    int maximaIdx = 0;

    int maxProfit = 0;
    while( minimaIdx < n && maximaIdx < n ){

        if( A[minimaIdx] < A[maximaIdx] ){
            maxProfit = max( maxProfit, A[maximaIdx] - A[minimaIdx] );
            maximaIdx++;
        } else {
            minimaIdx = maximaIdx;
            maximaIdx++;
        }
    }
    return maxProfit;
}

int main() {

    vector<int> A = { 100, 180, 260, 310, 40, 535, 695 };
    cout<<"Ans: "<<maxProfit( A )<<endl;

    return 0;
}