#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void resetMap( const vector<string> &B, int& overallCtr, unordered_map<string, int>& stringMap ){

    overallCtr = 0;

    // set all to 0
    for( int i=0; i<B.size(); i++ ){

        auto it = stringMap.find( B[i] );
        if( it == stringMap.end() ) {
            pair<string, int> pair1( B[i], 0 );
            stringMap.insert( pair1 );
        } else {
            it->second = 0;
        }
        overallCtr++;
    }

    // set to ctr
    for( int i=0; i<B.size(); i++ ){

        auto it = stringMap.find( B[i] );
        if( it != stringMap.end() ) {
            it->second++;
        }
    }
}

vector<int> findSubstring(string A, const vector<string> &B) {

    unordered_map<string, int> stringMap;
    int overallCtr;

    resetMap( B, overallCtr, stringMap );

    unsigned long int STR_LEN = 0;
    if( B.size() > 0 )
        STR_LEN = B[0].length();

    vector<int> ans;

    int currStartIdx = -1;

    for( int i=0; i<A.length(); i++ ){

        string currStr = A.substr(i, STR_LEN);
        cout<<"i: "<<i<<endl;
        cout<<"currStr: "<<currStr<<endl;
        auto it = stringMap.find( currStr );
        if( it != stringMap.end() && it->second > 0 ){

            cout<<"found with count > 0 "<<endl;
            it->second--;
            overallCtr--;

            if( currStartIdx == -1 )
                currStartIdx = i;

            if( overallCtr == 0 ){
                cout<<"overallCtr reached 0!"<<endl;
                ans.push_back( currStartIdx );
                resetMap( B, overallCtr, stringMap );

                i = currStartIdx;
                currStartIdx = -1;

            } else {
                i += ( STR_LEN - 1 );
            }

        } else {
            cout<<"not found"<<endl;
            resetMap( B, overallCtr, stringMap );

            if( currStartIdx != -1 )
                i = currStartIdx;
            currStartIdx = -1;
        }
        cout<<"overallCtr: "<<overallCtr<<endl;
        cout<<"currStartIdx: "<<currStartIdx<<endl;
        cout<<endl;
    }
    return ans;
}

int main() {

//    string S = "barfoothefoobarman";
//    vector<string> L = {
//            "foo",
//            "bar"
//    };      //  [ 0, 9 ]
//
//    printIntVector( findSubstring( S, L ) );
//
//    string S = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ";
//    vector<string> L = {
//            "aaa", "aaa", "aaa", "aaa", "aaa"
//    };      // [ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 ]
//
//    printIntVector( findSubstring( S, L ) );

    string S = "bcabbcaabbccacacbabccacaababcbb";
    vector<string> L = {
            "c", "b", "a", "c", "a", "a", "a", "b", "c"
    };      // [ 6 16 17 18 19 20 ]

    printIntVector( findSubstring( S, L ) );
    return 0;
}