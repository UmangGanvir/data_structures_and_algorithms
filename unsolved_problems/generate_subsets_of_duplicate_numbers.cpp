#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

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

void generateSubsets( vector<int>& A, vector<int>& curr, long long int currSum, set<long long int>& sumSet, int index, vector<vector<int>>& ans ){

    if( index == A.size() ){

//        cout<<"currSum: "<<currSum<<endl;
//
//        cout<<"pre set: ";
//        for( auto it = sumSet.begin(); it != sumSet.end(); it++ ){
//            cout<<*it<<" ";
//        }
//        cout<<endl;

        if( sumSet.find( currSum ) == sumSet.end() ){
            sumSet.insert( currSum );
            ans.push_back( curr );
        }

//        cout<<"post set: ";
//        for( auto it = sumSet.begin(); it != sumSet.end(); it++ ){
//            cout<<*it<<" ";
//        }
//        cout<<endl;

        return;
    }

    // Exclude the current choice
    generateSubsets( A, curr, currSum, sumSet, index+1, ans );

    // Include the current choice
    curr.push_back( A[index] );

    long long int a = ( numeric_limits<int>::max() );
    a += A[index];
    a *= ( curr.size() + 1 );
    currSum += ( a );
    generateSubsets( A, curr, currSum, sumSet, index+1, ans );

    curr.pop_back();
}

vector<vector<int> > subsetsWithDup(vector<int> &A) {

    sort( A.begin(), A.end() );
    vector<vector<int>> ans;
    vector<int> curr;
    long long int currSum = 0;
    set<long long int> sumSet;
    generateSubsets( A, curr, currSum, sumSet, 0, ans );
    sort( ans.begin(), ans.end() );
    return ans;
}


int main() {

//    vector<int> A = { 6, 6, 3, 3, 6, 5 };

    //[]
    // [3 ]
    // [3 3 ]
    // [3 3 5 ]
    // [3 3 5 6 ]
    // [3 3 5 6 6 ]
    // [3 3 5 6 6 6 ]
    // [3 3 6 ]
    // [3 3 6 6 ]
    // [3 3 6 6 6 ]
    // [3 5 ]
    // [3 5 6 ]
    // [3 5 6 6 ]
    // [3 5 6 6 6 ]
    // [3 6 ]
    // [3 6 6 ]
    // [3 6 6 6 ]
    // [5 ]
    // [5 6 ]
    // [5 6 6 ]
    // [5 6 6 6 ]
    // [6 ]
    // [6 6 ]
    // [6 6 6 ]

    vector<int> A = { 4, 2, 2, 2, 7, 7, 5, 8, 7, 1 };

    // [] [1 ] [1 2 ] [1 2 2 ] [1 2 2 2 ] [1 2 2 2 4 ] [1 2 2 2 4 5 ] [1 2 2 2 4 5 7 ] [1 2 2 2 4 5 7 7 ] [1 2 2 2 4 5 7 7 7 ] [1 2 2 2 4 5 7 7 7 8 ] [1 2 2 2 4 5 7 7 8 ] [1 2 2 2 4 5 7 8 ] [1 2 2 2 4 5 8 ] [1 2 2 2 4 7 ] [1 2 2 2 4 7 7 ] [1 2 2 2 4 7 7 7 ] [1 2 2 2 4 7 7 7 8 ] [1 2 2 2 4 7 7 8 ] [1 2 2 2 4 7 8 ] [1 2 2 2 4 8 ] [1 2 2 2 5 ] [1 2 2 2 5 7 ] [1 2 2 2 5 7 7 ] [1 2 2 2 5 7 7 7 ] [1 2 2 2 5 7 7 7 8 ] [1 2 2 2 5 7 7 8 ] [1 2 2 2 5 7 8 ] [1 2 2 2 5 8 ] [1 2 2 2 7 ] [1 2 2 2 7 7 ] [1 2 2 2 7 7 7 ] [1 2 2 2 7 7 7 8 ] [1 2 2 2 7 7 8 ] [1 2 2 2 7 8 ] [1 2 2 2 8 ] [1 2 2 4 ] [1 2 2 4 5 ] [1 2 2 4 5 7 ] [1 2 2 4 5 7 7 ] [1 2 2 4 5 7 7 7 ] [1 2 2 4 5 7 7 7 8 ] [1 2 2 4 5 7 7 8 ] [1 2 2 4 5 7 8 ] [1 2 2 4 5 8 ] [1 2 2 4 7 ] [1 2 2 4 7 7 ] [1 2 2 4 7 7 7 ] [1 2 2 4 7 7 7 8 ] [1 2 2 4 7 7 8 ] [1 2 2 4 7 8 ] [1 2 2 4 8 ] [1 2 2 5 ] [1 2 2 5 7 ] [1 2 2 5 7 7 ] [1 2 2 5 7 7 7 ] [1 2 2 5 7 7 7 8 ] [1 2 2 5 7 7 8 ] [1 2 2 5 7 8 ] [1 2 2 5 8 ] [1 2 2 7 ] [1 2 2 7 7 ] [1 2 2 7 7 7 ] [1 2 2 7 7 7 8 ] [1 2 2 7 7 8 ] [1 2 2 7 8 ] [1 2 2 8 ] [1 2 4 ] [1 2 4 5 ] [1 2 4 5 7 ] [1 2 4 5 7 7 ] [1 2 4 5 7 7 7 ] [1 2 4 5 7 7 7 8 ] [1 2 4 5 7 7 8 ] [1 2 4 5 7 8 ] [1 2 4 5 8 ] [1 2 4 7 ] [1 2 4 7 7 ] [1 2 4 7 7 7 ] [1 2 4 7 7 7 8 ] [1 2 4 7 7 8 ] [1 2 4 7 8 ] [1 2 4 8 ] [1 2 5 ] [1 2 5 7 ] [1 2 5 7 7 ] [1 2 5 7 7 7 ] [1 2 5 7 7 7 8 ] [1 2 5 7 7 8 ] [1 2 5 7 8 ] [1 2 5 8 ] [1 2 7 ] [1 2 7 7 ] [1 2 7 7 7 ] [1 2 7 7 7 8 ] [1 2 7 7 8 ] [1 2 7 8 ] [1 2 8 ] [1 4 ] [1 4 5 ] [1 4 5 7 ] [1 4 5 7 7 ] [1 4 5 7 7 7 ] [1 4 5 7 7 7 8 ] [1 4 5 7 7 8 ] [1 4 5 7 8 ] [1 4 5 8 ] [1 4 7 ] [1 4 7 7 ] [1 4 7 7 7 ] [1 4 7 7 7 8 ] [1 4 7 7 8 ] [1 4 7 8 ] [1 4 8 ] [1 5 ] [1 5 7 ] [1 5 7 7 ] [1 5 7 7 7 ] [1 5 7 7 7 8 ] [1 5 7 7 8 ] [1 5 7 8 ] [1 5 8 ] [1 7 ] [1 7 7 ] [1 7 7 7 ] [1 7 7 7 8 ] [1 7 7 8 ] [1 7 8 ] [1 8 ] [2 ] [2 2 ] [2 2 2 ] [2 2 2 4 ] [2 2 2 4 5 ] [2 2 2 4 5 7 ] [2 2 2 4 5 7 7 ] [2 2 2 4 5 7 7 7 ] [2 2 2 4 5 7 7 7 8 ] [2 2 2 4 5 7 7 8 ] [2 2 2 4 5 7 8 ] [2 2 2 4 5 8 ] [2 2 2 4 7 ] [2 2 2 4 7 7 ] [2 2 2 4 7 7 7 ] [2 2 2 4 7 7 7 8 ] [2 2 2 4 7 7 8 ] [2 2 2 4 7 8 ] [2 2 2 4 8 ] [2 2 2 5 ] [2 2 2 5 7 ] [2 2 2 5 7 7 ] [2 2 2 5 7 7 7 ] [2 2 2 5 7 7 7 8 ] [2 2 2 5 7 7 8 ] [2 2 2 5 7 8 ] [2 2 2 5 8 ] [2 2 2 7 ] [2 2 2 7 7 ] [2 2 2 7 7 7 ] [2 2 2 7 7 7 8 ] [2 2 2 7 7 8 ] [2 2 2 7 8 ] [2 2 2 8 ] [2 2 4 ] [2 2 4 5 ] [2 2 4 5 7 ] [2 2 4 5 7 7 ] [2 2 4 5 7 7 7 ] [2 2 4 5 7 7 7 8 ] [2 2 4 5 7 7 8 ] [2 2 4 5 7 8 ] [2 2 4 5 8 ] [2 2 4 7 ] [2 2 4 7 7 ] [2 2 4 7 7 7 ] [2 2 4 7 7 7 8 ] [2 2 4 7 7 8 ] [2 2 4 7 8 ] [2 2 4 8 ] [2 2 5 ] [2 2 5 7 ] [2 2 5 7 7 ] [2 2 5 7 7 7 ] [2 2 5 7 7 7 8 ] [2 2 5 7 7 8 ] [2 2 5 7 8 ] [2 2 5 8 ] [2 2 7 ] [2 2 7 7 ] [2 2 7 7 7 ] [2 2 7 7 7 8 ] [2 2 7 7 8 ] [2 2 7 8 ] [2 2 8 ] [2 4 ] [2 4 5 ] [2 4 5 7 ] [2 4 5 7 7 ] [2 4 5 7 7 7 ] [2 4 5 7 7 7 8 ] [2 4 5 7 7 8 ] [2 4 5 7 8 ] [2 4 5 8 ] [2 4 7 ] [2 4 7 7 ] [2 4 7 7 7 ] [2 4 7 7 7 8 ] [2 4 7 7 8 ] [2 4 7 8 ] [2 4 8 ] [2 5 ] [2 5 7 ] [2 5 7 7 ] [2 5 7 7 7 ] [2 5 7 7 7 8 ] [2 5 7 7 8 ] [2 5 7 8 ] [2 5 8 ] [2 7 ] [2 7 7 ] [2 7 7 7 ] [2 7 7 7 8 ] [2 7 7 8 ] [2 7 8 ] [2 8 ] [4 ] [4 5 ] [4 5 7 ] [4 5 7 7 ] [4 5 7 7 7 ] [4 5 7 7 7 8 ] [4 5 7 7 8 ] [4 5 7 8 ] [4 5 8 ] [4 7 ] [4 7 7 ] [4 7 7 7 ] [4 7 7 7 8 ] [4 7 7 8 ] [4 7 8 ] [4 8 ] [5 ] [5 7 ] [5 7 7 ] [5 7 7 7 ] [5 7 7 7 8 ] [5 7 7 8 ] [5 7 8 ] [5 8 ] [7 ] [7 7 ] [7 7 7 ] [7 7 7 8 ] [7 7 8 ] [7 8 ] [8 ]

    printVectorOfVectorInt( subsetsWithDup( A ) );

    return 0;
}