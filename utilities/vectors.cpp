#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/* vector print */

void printIntVector( vector<int> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void printCharVector( vector<char> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void printStringVector( vector<string> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<endl;
    cout<<endl;
}

/* vector of vectors print */

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vec[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //
    return 0;
}