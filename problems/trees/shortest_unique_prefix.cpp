#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printStringVector( vector<string> vec ){
    cout<<"Printing string vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

class Trie {
public:
    vector<int> wordCounts;
    vector<Trie*> arr;
    Trie(){
        vector<int> wordsArr(26, 0);
        this->wordCounts = wordsArr;
        vector<Trie*> arr1(26, NULL);
        this->arr = arr1;
    }
};

void insertIntoTrie( string str, Trie* root ){

    Trie* trav = root;

    for( int i=0; i<str.length(); i++ ){

        Trie* nextTrieNode = trav->arr[ (int)str[i] - 97 ];
        if( nextTrieNode == NULL )
            nextTrieNode = new Trie();

        trav->arr[ (int)str[i] - 97 ] = nextTrieNode;
        trav->wordCounts[ (int)str[i] - 97 ]++;
        trav = nextTrieNode;
    }
}

string fetchMinimalStringFromTrie( string str, Trie* root ){

    string ans = "";
    Trie* trav = root;
    for( int i=0; i<str.length(); i++ ){
        ans += string(1, str[i]);
        if( trav->wordCounts[ (int)str[i] - 97 ] == 1 )
            break;
        trav = trav->arr[ (int)str[i] - 97 ];
    }
    return ans;

}
vector<string> prefix(vector<string> &A) {

    Trie* root = new Trie();

    // Form the dictionary
    for( int i=0; i<A.size(); i++ ){
        insertIntoTrie( A[i], root );
    }

    // Find shortest prefix for representation
    vector<string> ans( A.size() );
    for( int i=0; i<A.size(); i++ ){
        ans[i] = fetchMinimalStringFromTrie( A[i], root );
    }

    return ans;
}


int main() {

    vector<string> A = { "zebra", "dog", "duck", "dove" };
    printStringVector( prefix( A ) );
    return 0;
}