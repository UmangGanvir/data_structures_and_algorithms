#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

vector<int> solve(vector<int> &A, vector<int> &B) {

    sort( A.begin(), A.end() );
    sort( B.begin(), B.end() );

    int n = (int) (A.size());
    map<int,int> complementCountMap;
    for( int i=0; i<n; i++ ){
        int numb = B[i];
        auto it = complementCountMap.find( numb );
        if( it != complementCountMap.end() ){
            it->second++;
        } else {
            pair<int,int> pair1( numb, 1 );
            complementCountMap.insert( pair1 );
        }
    }

    int highest = A[n-1] + B[n-1];
    int ctr=0;
    vector<int> ans( n, -1 );
    while( ctr < n ){

        for( int i=n-1; i>=0; i-- ){

            int complement = highest - A[i];
            auto it = complementCountMap.find( complement );
            if( it != complementCountMap.end() ){

                cout<<"found: "<<endl;
                cout<<"highest: "<<highest<<endl;
                cout<<"numb: "<<A[i]<<endl;
                cout<<"complement: "<<complement<<endl;
                cout<<"count: "<<it->second<<endl;
                cout<<endl;

                int count = it->second;
                while( count-- && ctr < n ){
                    ans[ctr] = highest;
                    ctr++;
                }

            }
        }
        highest--;
    }
    return ans;
}

int main() {

//    vector<int> A = { 1, 2 };
//    vector<int> B = { 3, 4 };
//    printIntVector( solve( A, B ) );        // 6, 5
//
//    vector<int> A = { 1,4,2,3 };
//    vector<int> B = { 2,5,1,6 };
//    printIntVector( solve( A, B ) );            // 10 9 9 8

    vector<int> A = { 36, 27, -35, 43, -15, 36, 42, -1, -29, 12, -23, 40, 9, 13, -24, -10, -24, 22, -14, -39, 18, 17, -21, 32, -20, 12, -27, 17, -15, -21, -48, -28, 8, 19, 17, 43, 6, -39, -8, -21, 23, -29, -31, 34, -13, 48, -26, -35, 20, -37, -24, 41, 30, 6, 23, 12, 20, 46, 31, -45, -25, 34, -23, -14, -45, -4, -21, -37, 7, -26, 45, 32, -5, -36, 17, -16, 14, -7, 0, 37, -42, 26, 28 };
    vector<int> B = { 38, 34, -47, 1, 4, 49, -18, 10, 26, 18, -11, -38, -24, 36, 44, -11, 45, 20, -16, 28, 17, -49, 47, -48, -33, 42, 2, 6, -49, 30, 36, -9, 15, 39, -6, -31, -10, -21, -19, -33, 47, 21, 31, 25, -41, -23, 17, 6, 47, 3, 36, 15, -44, 33, -31, -26, -22, 21, -18, -21, -47, -31, 20, 18, -42, -35, -10, -1, 46, -27, -32, -5, -4, 1, -29, 5, 29, 38, 14, -22, -9, 0, 43 };
    printIntVector( solve( A, B ) ); // 97 95 95 95 95 94 94 93 93 93 93 92 92 92 92 92 92 92 91 91 91 91 90 90 90 90 90 90 90 90 90 90 89 89 89 89 89 89 89 89 88 88 88 88 88 88 88 88 87 87 87 87 87 87 87 87 87 86 86 86 86 86 86 86 86 85 85 85 85 85 85 85 85 84 84 84 84 84 84 84 84 84 84

    return 0;
}