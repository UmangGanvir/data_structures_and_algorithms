#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

vector<int> dNums(vector<int> &A, int B) {

    int n = (int) A.size();

    int currUniCount = 0;
    map<int,int> numbOccurrenceMap;

    vector<int> ans;

    for( int i=0; i<n; i++ ){

        if( i < B ){

            // Filling first K in window

            auto it = numbOccurrenceMap.find( A[i] );
            if( it != numbOccurrenceMap.end() ){
                it->second++;
            } else {
                pair<int, int> pair1( A[i], 1 );
                numbOccurrenceMap.insert( pair1 );
                currUniCount++;
            }

            if( i == B-1 ){
                ans.push_back( currUniCount );
            }

        } else {

            auto it = numbOccurrenceMap.find( A[i] );
            if( it != numbOccurrenceMap.end() ){
                it->second++;

                if( it->second == 1 ){
                    currUniCount++;
                }

            } else {
                pair<int, int> pair1( A[i], 1 );
                numbOccurrenceMap.insert( pair1 );
                currUniCount++;
            }

            auto it2 = numbOccurrenceMap.find( A[i-B] );
            if( it2 != numbOccurrenceMap.end() ){
                it2->second--;

                if( it2->second == 0 )
                    currUniCount--;
            }

            ans.push_back( currUniCount );

        }
    }

    return ans;

}

int main() {

//    vector<int> A = { 1, 2, 1, 3, 4, 3 };
//    int k = 3;
//    printIntVector( dNums( A, k ) );    // 2 3 3 2

    vector<int> A = { 31, 51, 31, 51, 31, 31, 31, 31, 31, 31, 51, 31, 31 };
    int k = 3;
    printIntVector( dNums( A, k ) );    // 2 3 3 2

    return 0;
}