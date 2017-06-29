#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    cout<<"Printing vector of int vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void rotateArrayUtil( vector<vector<int> > &A, int level ){

    unsigned long int n = A.size();

    for( int i=level; i<n-level-1; i++ ){

        int temp = A[level][i];

        A[level][i] = A[ n - 1 - i ][ level ];

        A[ n - 1 - i ][ level ] = A[ n - 1 - level ][ n - 1 - i ];

        A[ n - 1 - level ][ n - 1 - i ] = A[i][ n - 1 - level ];

        A[ i ][ n - 1 - level ] = temp;
    }
}

int rotateArray( vector<vector<int> > &A ){

    unsigned long int n = A.size();
    for( int i=0; i<n/2; i++ )
        rotateArrayUtil( A, i );
}

int main() {

    vector<vector<int>> A = {
            { 1, 2 },
            { 3, 4 }
    };
    rotateArray( A );
    printVectorOfVectorInt( A );
    /*
     * 3 1
     * 4 2
     * */

    vector<vector<int>> B = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
    };
    rotateArray( B );
    printVectorOfVectorInt( B );
    /*
     * 7 4 1
     * 8 5 2
     * 9 6 3
     * */

    vector<vector<int>> C = {
            { 31, 32, 228, 333 },
            { 79, 197, 241, 246 },
            { 77, 84, 126, 337 },
            { 110, 291, 356, 371 }
    };
    rotateArray( C );
    printVectorOfVectorInt( C );
    /*
     * 110 77 79 31
     * 291 84 197 32
     * 356 126 241 228
     * 371 337 246 333
     * */

    return 0;
}