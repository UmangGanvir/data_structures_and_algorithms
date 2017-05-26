#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &A) {

    unsigned long int rows = A.size();
    unsigned long int cols = A[0].size();

    vector<vector<int>> uniquePathTillThisPoint( A.size(), vector<int>(A[0].size(), 0) );

    for( int i=0; i<rows; i++ ){
        for( int j=0; j<cols; j++ ){


            if( A[i][j] == 0 ){

                // Empty Space
                if( i == 0 && j == 0 )
                    uniquePathTillThisPoint[i][j] = 1;  // starting point

                if( i > 0 && A[i-1][j] == 0 )
                    uniquePathTillThisPoint[i][j] += uniquePathTillThisPoint[i-1][j];

                if( j > 0 && A[i][j-1] == 0 )
                    uniquePathTillThisPoint[i][j] += uniquePathTillThisPoint[i][j-1];

            } else {

                // Obstacle

            }

        }
    }
    return uniquePathTillThisPoint[rows-1][cols-1];
}

int main() {

    vector<vector<int>> A = {
            { 0,0,0 },
            { 0,1,0 },
            { 0,0,0 }
    };
    cout<<"Ans: "<<uniquePathsWithObstacles( A )<<endl;

    return 0;
}