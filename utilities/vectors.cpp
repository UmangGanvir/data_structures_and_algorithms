#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/* vector print */

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void printCharVector( vector<char> vec ){
    cout<<"Printing char vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void printStringVector( vector<string> vec ){
    cout<<"Printing string vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

/* vector of vectors print */

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

void printVectorOfVectorString( vector<vector<string>> vecOfVec ){
    cout<<"Printing vector of string vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

int main() {
    //
    return 0;
}