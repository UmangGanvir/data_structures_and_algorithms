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

class SortNode {
public:
    int originalIdx;
    int goodness;
    SortNode( int idx, int goodness1 ){
        this->originalIdx = idx;
        this->goodness = goodness1;
    }
};

bool SortNodesComp( SortNode* a, SortNode* b ){
    return a->goodness > b->goodness;
}

vector<int> solve(string A, vector<string> &B) {

    if( A.length() == 0 ){
        vector<int> ans( B.size() );
        for( int i=0; i<B.size(); i++ ){
            ans[i] = i;
        }
        return ans;
    }

    unordered_map<string, bool> goodWords;

    int startIdx = 0;
    for( int i=1; i<A.length(); i++ ){
        if( A[i] == '_' ){
            string currStr = A.substr( startIdx, i - startIdx );
            pair<string,bool> pair1( currStr, true );
            goodWords.insert( pair1 );
            startIdx = i+1;
        }

        if( i == A.length() - 1 ){
            string currStr = A.substr( startIdx, i - startIdx + 1 );
            pair<string,bool> pair1( currStr, true );
            goodWords.insert( pair1 );
        }
    }

    vector<SortNode*> sortNodes( B.size() );

    for( int i=0; i<B.size(); i++ ){

        // For each sort node
        int goodness = 0;

        startIdx = 0;
        for( int j=0; j<B[i].length(); j++ ){

            if( B[i][j] == '_' ){
                string currStr = B[i].substr( startIdx, j - startIdx );

                auto it = goodWords.find( currStr );
                if( it != goodWords.end() )
                    goodness++;

                startIdx = j+1;
            }

            if( j == B[i].length() - 1 ){
                string currStr = B[i].substr( startIdx, j - startIdx + 1 );

                auto it = goodWords.find( currStr );
                if( it != goodWords.end() )
                    goodness++;
            }
        }

        sortNodes[i] = new SortNode( i, goodness );
    }

    stable_sort( sortNodes.begin(), sortNodes.end(), SortNodesComp );

    vector<int> ans( B.size() );
    for( int i =0; i<B.size(); i++ ){
        ans[i] = sortNodes[i]->originalIdx;
    }
    return ans;
}

int main() {

    string A = "cool_ice_wifi";
    vector<string> B = { "water_is_cool", "cold_ice_drink", "cool_wifi_speed" };
    printIntVector( solve( A, B ) );  // 2, 0, 1

    string A1 = "play_boy";
    vector<string> B1 = { "smart_guy", "girl_and_boy_play", "play_ground" };
    printIntVector( solve( A1, B1 ) );  // 1, 2, 0

    return 0;
}