#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

void printStringVector( vector<string> vec ){
    cout<<"Printing string vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

bool isPalindromic( string str ){
    for( int i=0; i<str.length()/2; i++ ){
        if( str[i] != str[ str.length() - 1 - i ] )
            return false;
    }
    return true;
}

void generatePalindromicSubStrings( vector<string> palindromicStrings, int index, vector<vector<string>>& ans ){

    cout<<"index: "<<index<<endl;

    if( index == palindromicStrings.size() )
        return;


    for( int j=index+1; j<palindromicStrings.size(); j++ ){

        string currStr = "";
        for( int k=index; k<=j; k++ ){
            currStr += palindromicStrings[k];
        }

        if( isPalindromic( currStr ) ){

            cout<<"palindromic currStr: "<<currStr<<endl;

            vector<string> newPalindromicStrings;
            int ctr = 0;
            while( ctr < index ){
                newPalindromicStrings.push_back( palindromicStrings[ctr] );
                ctr++;
            }
            newPalindromicStrings.push_back( currStr );
            ctr = j+1;
            while( ctr < palindromicStrings.size() ){
                newPalindromicStrings.push_back( palindromicStrings[ctr] );
                ctr++;
            }

            printStringVector( newPalindromicStrings );
            cout<<endl;
            ans.push_back( newPalindromicStrings );

            generatePalindromicSubStrings( newPalindromicStrings, index+1, ans );

        } else {

            cout<<"not palindromic currStr: "<<currStr<<endl<<endl;
        }
    }

    generatePalindromicSubStrings( palindromicStrings, index+1, ans );
}

vector<vector<string> > partition( string A ){

    vector<vector<string>> ans;

    vector<string> originalStrChars;
    for( int i =0; i<A.length(); i++ ){
        originalStrChars.push_back( string( 1, A[i]) );
    }

    ans.push_back( originalStrChars );
    generatePalindromicSubStrings( originalStrChars, 0, ans );
    sort( ans.begin(), ans.end() );
    return ans;
}

int main() {

    string A = "aaaab";
//    string A = "efe";
    vector<vector<string>> ans = partition( A );
    cout<<"Final Ans!"<<endl;
    printVectorOfVectorString( ans );
    return 0;
}