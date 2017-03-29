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

void generateString( string& currStr, vector<char>& options, vector<string>& ans ){

    if( options.empty() ){
        ans.push_back( currStr );
        return;
    }

    for( int i=0; i<options.size(); i++ ){

        char optionI = options[i];

        currStr += string( 1, optionI );
        options.erase( options.begin() + i );
        generateString( currStr, options, ans );

        options.insert( options.begin() + i, optionI );
        currStr = currStr.substr( 0, currStr.length() - 1 );
    }
}

vector<string> generateAllPermutations( string A ){

    vector<string> ans;
    string curr = "";
    vector<char> options;
    for( int i=0; i<A.length(); i++ ){
        options.push_back( A[i] );
    }
    generateString( curr, options, ans );
    return ans;
}

int main() {

    string A = "1234";

    printStringVector( generateAllPermutations( A ) );

    return 0;
}