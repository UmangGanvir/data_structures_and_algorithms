#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printStringVector( vector<string> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<endl;
    cout<<endl;
}

void generatePermutations( string& currStr, string& A, int len, vector<string>& ans ){

    if( currStr.length() == len ){
        ans.push_back( currStr );
        return;
    }

    // iterate over options
    for( int i=0; i<A.length(); i++ ){

        currStr += string( 1, A[i] );
        generatePermutations( currStr, A, len, ans );

        // undo last step
        currStr = currStr.substr( 0, currStr.length()-1 );
    }

}

vector<string> generateAllPermutationsOfLen( string A, int len ){
    vector<string> ans;
    string currStr = "";
    generatePermutations( currStr, A, len, ans );
    return ans;
}

int main() {

    string A = "ab";

    printStringVector( generateAllPermutationsOfLen( A, 3 ) );

    return 0;
}