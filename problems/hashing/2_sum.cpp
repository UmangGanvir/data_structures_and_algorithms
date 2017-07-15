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

vector<int> twoSum(const vector<int> &A, int B) {

    int index1 = -1;
    int index2 = -1;

    unordered_map<int,int> numbIdxMap;
    for( int i=0; i<A.size(); i++ ){

        auto it = numbIdxMap.find( B - A[i] );
        if( it != numbIdxMap.end() ){

            if( index1 == -1 ) {
                index1 = it->second;
                index2 = i;
                break;
            }

        } else {

            pair<int,int> pair1( A[i], i );
            numbIdxMap.insert( pair1 );
        }
    }

    vector<int> ans;
    if( index1 == -1 )
        return ans;

    ans.push_back( index1 + 1 );
    ans.push_back( index2 + 1 );

    return ans;
}

int main() {

    vector<int> A = { 2, 7, 11, 15 };
    int B = 9;
    printIntVector( twoSum( A, B ) );

    return 0;
}