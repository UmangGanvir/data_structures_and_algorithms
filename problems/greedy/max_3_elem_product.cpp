#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxp3( vector<int> &A ){

    sort( A.begin(), A.end());

    unsigned long int n = A.size();

    int leftTwoRightOne = A[0]*A[1]*A[n - 1];
    int rightThree = A[n-3]*A[n-2]*A[n-1];

    return max( leftTwoRightOne, rightThree );
}

int main() {

//    vector<int> A = { 0, -1, 3, 100, 70, 50 };
//    cout<<"Ans: "<<maxp3( A )<<endl;          // 350000

    vector<int> B = { 0, -1, 3, 100, -70, -50 };
    cout<<"Ans: "<<maxp3( B )<<endl;            // 350000

    return 0;
}