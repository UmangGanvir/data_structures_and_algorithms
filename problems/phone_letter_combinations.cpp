#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVector( vector<string> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

vector<vector<char>> phoneDigitMap = {
        { '0' },
        { '1' },
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's' },
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z' },
};

void generateString( string& current, int index, string str, vector<string>& ans ){

    if( index == str.length() ){
        ans.push_back( current );
        return;
    }

    int digit = (int)str[index] - 48;
    for( int i=0; i<phoneDigitMap[digit].size(); i++ ){
        current += string( 1, phoneDigitMap[digit][i] );
        generateString( current, index+1, str, ans );
        current = current.substr( 0, current.length() - 1 );
    }

}

vector<string> letterCombinations( string A ){

    vector<string> ans;
    string curr = "";
    generateString( curr, 0, A, ans );
    return ans;
}

int main() {

    string A = "23";

    printVector( letterCombinations( A ) );

    return 0;
}