#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void printStringVector( vector<string> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<endl;
    cout<<endl;
}

void swapForAllLR( string& currStr, int l, unsigned long int r, vector<string>& ans ){

    if( l == r ){
        ans.push_back( currStr );
        return;
    }

    for( int i=l; i<=r; i++ ){
        swap( currStr[l], currStr[i] );
        swapForAllLR( currStr, l+1, r, ans );
        swap( currStr[l], currStr[i] );
    }
}

vector<string> generateAllPermutations( string A ){

    vector<string> ans;
    swapForAllLR( A, 0, A.length() -1, ans );
    return ans;
}

int main() {

    string A = "1234";

    printStringVector( generateAllPermutations( A ) );

    return 0;
}