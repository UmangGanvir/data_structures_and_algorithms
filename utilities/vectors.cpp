#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

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

int main() {
    //
    return 0;
}