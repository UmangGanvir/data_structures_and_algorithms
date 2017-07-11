#include <iostream>
#include <algorithm>
#include <vector>
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

void getCombinations( vector<int>& A, vector<int>& curr, int index, int k, vector<vector<int>>& ans ){

    if( curr.size() == k ){
        ans.push_back( curr );
        return;
    }

    for( int i=index; i<A.size(); i++ ){
        curr.push_back( A[i] );
        getCombinations( A, curr, i+1, k, ans );
        curr.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {

    vector<vector<int>> ans;
    vector<int> A( n, -1 );
    for( int i=0; i<n; i++ ){
        A[i] = i+1;
    }
    vector<int> curr;
    getCombinations( A, curr, 0, k, ans );
    sort( ans.begin(), ans.end() );
    return ans;
}

int main() {

//    vector<int> A = { 1, 2, 3 };
    int n=4, k=2;
    printVectorOfVectorInt( combine( n, k ) );

    return 0;
}