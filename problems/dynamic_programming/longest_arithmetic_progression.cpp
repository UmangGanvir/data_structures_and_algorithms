#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int countAllNextOccurrence( int lastNumb, int lastNumbIdx, int diff, unsigned long int arrSize, unordered_map<int, int>& valueIndexMap ){
    if( lastNumbIdx >= arrSize - 1 )
        return 0;

    int nextNumb = lastNumb + diff;
    auto it = valueIndexMap.find( nextNumb );
    if( it == valueIndexMap.end() )
        return 0;

    if( it->second < lastNumbIdx )
        return 0;

    return 1 + countAllNextOccurrence( nextNumb, it->second, diff, arrSize, valueIndexMap );
}

int solve(const vector<int>& A ){

    unordered_map<int, int> valueIndexMap;
    unsigned long int n = A.size();

    if( n <= 2 )
        return (int) n;

    // store value, index
    for( int i=0; i<n; i++ ){
        auto it = valueIndexMap.find( A[i] );
        if( it != valueIndexMap.end() ){
            it->second = i;
        } else {
            pair<int, int> pair1( A[i], i );
            valueIndexMap.insert( pair1 );
        }
    }

    int overallMaxLen = 0;
    for( int i=0; i<n-1; i++ ){
        // for each pair of numbers
        for( int j=i+1; j<n; j++ ){

            if( i == j )
                continue;

            int diff = A[j]-A[i];

            if( diff != 0 ){
                int maxLen = 2 + countAllNextOccurrence( A[j], j, diff, n, valueIndexMap);
                if( maxLen > overallMaxLen )
                    overallMaxLen = maxLen;
            } else {
                int currMax = 2;
                for( int k = j+1; k<n; k++ ) {
                    if (A[k] == A[j]) {
                        currMax++;
                    }
                }
                if( currMax > overallMaxLen )
                    overallMaxLen = currMax;
            }
        }
    }

    return overallMaxLen;
}

int main() {
//
    vector<int> A = { 3, 6, 9, 12 };
    cout<<"Longest Arithmetic Progression: "<<( solve( A ) )<<endl;

    vector<int> B = { 9, 4, 7, 2, 10 };
    cout<<"Longest Arithmetic Progression: "<<( solve( B ) )<<endl;

    vector<int> C = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    cout<<"Longest Arithmetic Progression: "<<( solve( C ) )<<endl;

    return 0;
}