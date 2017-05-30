#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void printStringVector( vector<string> vec ){
    cout<<"Printing string vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<endl;
    cout<<endl;
}

bool canStringFormValidSentence(
        string A, int totalStringSize, vector<string>& currWords, int& currWordsLen,
        unordered_map<string,bool>& dict, unordered_map<string, pair<bool, pair<vector<string>,int>>> stringAnsCache, vector<string>& ans
){

    auto itAnsCacheFind = stringAnsCache.find( A );
    if( itAnsCacheFind != stringAnsCache.end() ){

        if( !itAnsCacheFind->second.first )
            return false;

        currWords.insert( currWords.end(), itAnsCacheFind->second.second.first.begin(), itAnsCacheFind->second.second.first.end() );
        currWordsLen += itAnsCacheFind->second.second.second;

        if( currWordsLen == totalStringSize ){

            // One valid sentence found
            string ansStr = "";
            for( int j=0; j<currWords.size(); j++ ){
                ansStr += ( currWords[j] + " " );
            }
            ansStr = ansStr.substr( 0, ansStr.size() - 1 );
            ans.push_back( ansStr );
        }

        return true;
    }

    if( currWordsLen == totalStringSize ){

        // One valid sentence found
        string ansStr = "";
        for( int j=0; j<currWords.size(); j++ ){
            ansStr += ( currWords[j] + " " );
        }
        ansStr = ansStr.substr( 0, ansStr.size() - 1 );
        ans.push_back( ansStr );
    }

    if( A.size() == 0 ){
        return true;
    }

    bool found = false;
    for( int i=1; i<=A.size(); i++ ){

        string prefix = A.substr(0, (unsigned long) i);
        auto itPrefix = dict.find( prefix );
        if( itPrefix != dict.end() ){

            currWords.push_back( prefix );
            currWordsLen += prefix.size();
            if( canStringFormValidSentence( A.substr( i, A.size() - 1 ), totalStringSize, currWords, currWordsLen, dict, stringAnsCache, ans ) ){

                found = true;

                pair<vector<string>,int> l2Pair( currWords, currWordsLen );
                pair<bool, pair<vector<string>,int>> l1Pair( true, l2Pair );
                pair<string, pair<bool, pair<vector<string>,int>>> l0Pair( A.substr( i, A.size() - 1 ), l1Pair );
                stringAnsCache.insert( l0Pair );

            }
            currWords.pop_back();
            currWordsLen -= prefix.size();

        } else {
            //
        }
    }

    if( !found ){
        pair<vector<string>,int> l2Pair( currWords, currWordsLen );
        pair<bool, pair<vector<string>,int>> l1Pair( true, l2Pair );
        pair<string, pair<bool, pair<vector<string>,int>>> l0Pair( A, l1Pair );
        stringAnsCache.insert( l0Pair );
    }

    return found;

}

vector<string> wordBreak(string A, vector<string> &B) {

    unordered_map<string,bool> dict;
    for( int i=0; i<B.size(); i++ ){
        pair<string,bool> pair1( B[i], true );
        dict.insert( pair1 );
    }

    vector<string> currWords;
    int currWordsLen = 0;

    unordered_map<string, pair<bool, pair<vector<string>,int>>> stringAnsCache;

    vector<string> ans;
    canStringFormValidSentence(A, (int) A.size(), currWords, currWordsLen, dict, stringAnsCache, ans );
    sort( ans.begin(), ans.end() );
    return ans;
}

int main() {

    string A = "catsanddog";
    vector<string> B = { "cat", "cats", "and", "sand", "dog" };
    printStringVector( wordBreak( A, B ) );

    return 0;
}