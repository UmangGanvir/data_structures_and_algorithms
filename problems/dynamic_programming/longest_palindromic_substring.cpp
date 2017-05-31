#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestPalindromicSubstring( string str ){

    unsigned long int n = str.size();
    vector<vector<bool>> palindromeMap( n, vector<bool>( n, false ));

    for( int i=0; i<n; i++ )
        palindromeMap[i][i] = true;

    int ans = numeric_limits<int>::min();
    for( int size=2; size <= n; size++ ){
        for( int startIdx=0; startIdx < n-size+1; startIdx++ ){

            int endIdx = startIdx + size - 1;

            if( size == 2 )
                palindromeMap[startIdx][endIdx] = ( str[startIdx] == str[endIdx] );
            else
                palindromeMap[startIdx][endIdx] = ( str[startIdx] == str[endIdx] ) && palindromeMap[startIdx+1][endIdx-1];

            if( palindromeMap[startIdx][endIdx] && ( endIdx - startIdx + 1 > ans ) )
                ans = ( endIdx - startIdx + 1 );
        }
    }
    return ans;
}

int main() {

    string A = "geeksskeeg";
    cout<<"Ans: "<<longestPalindromicSubstring( A )<<endl;       // 10

    return 0;
}