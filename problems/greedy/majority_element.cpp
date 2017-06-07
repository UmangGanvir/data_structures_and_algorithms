#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int majorityElement(const vector<int> &A) {

    int maxCount = 1;

    int ansIdx = -1;

    map<int,int> numberCountMap;
    for( int i=0; i<A.size(); i++ ){
        auto it = numberCountMap.find( A[i] );
        if( it == numberCountMap.end() ){
            pair<int,int> pair1( A[i], 1 );
            numberCountMap.insert( pair1 );

            if( maxCount == 1 )
                ansIdx = i;

        } else {
            it->second++;

            if( it->second > maxCount ){
                maxCount = it->second;
                ansIdx = i;
            }

        }
    }

    return A[ansIdx];
}

int main() {

//    vector<int> A = { 2, 1, 2 };
//    cout<<"Ans: "<<majorityElement( A )<<endl;

    vector<int> B = { 668474 };
    cout<<"Ans: "<<majorityElement( B )<<endl;

    return 0;
}