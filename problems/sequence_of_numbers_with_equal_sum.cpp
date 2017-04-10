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

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    cout<<"Printing vector of int vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

vector<int> equal(vector<int> &A) {

    unordered_map<int, pair<int, int>> sumPairMap;

    bool foundAns = false;
    vector<int> ans;

    for( int i=0; i<A.size(); i++ ){
        for( int j=i+1; j<A.size(); j++ ){

            int sum = A[i] + A[j];
            auto it = sumPairMap.find( sum );
            if( it != sumPairMap.end() ){

                if( it->second.first >= i )
                    continue;

                if( it->second.second == i )
                    continue;

                if( it->second.second == j )
                    continue;

                if( !foundAns ){
                    foundAns = true;
                    ans.push_back( it->second.first );
                    ans.push_back( it->second.second );
                    ans.push_back( i );
                    ans.push_back( j );
                    continue;
                }

                if( it->second.first < ans[0] ){
                    ans[0] = it->second.first;
                    ans[1] = it->second.second;
                    ans[2] = i;
                    ans[3] = j;
                } else if( it->second.first == ans[0] ){

                    if( it->second.second < ans[1] ){
                        ans[0] = it->second.first;
                        ans[1] = it->second.second;
                        ans[2] = i;
                        ans[3] = j;

                    } else if( it->second.second == ans[1] ){

                        if( i < ans[2] ){
                            ans[0] = it->second.first;
                            ans[1] = it->second.second;
                            ans[2] = i;
                            ans[3] = j;

                        } else if( i == ans[2] ){

                            if( j < ans[3] ){
                                ans[0] = it->second.first;
                                ans[1] = it->second.second;
                                ans[2] = i;
                                ans[3] = j;
                            }

                        }

                    }

                }

            }

            pair<int, int> pair1( i, j );
            pair<int, pair<int,int>> pseudoPair( sum, pair1 );
            sumPairMap.insert( pseudoPair );

        }
    }
    return ans;
}

int main() {

//    vector<int> A = { 3, 4, 7, 1, 2, 9, 8 };    // [0, 2, 3, 5]
//    vector<int> A = { 1, 1, 1, 1, 1 };    // [0, 1, 2, 3]
    vector<int> A = { 1, 3, 3, 3, 3, 2, 2 };    // [0, 1, 5, 6]
    printIntVector( equal(A) );

    return 0;
}