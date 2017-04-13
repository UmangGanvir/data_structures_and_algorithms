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

vector<int> lszero(vector<int> &A) {

    vector<int> ans;

    if( A.size() == 0 )
        return ans;

    if( A.size() == 1 ){
        if( A[0] == 0 )
            return A;
        return ans;
    }

    int ansI = (int) A.size(), ansJ = (int) A.size();

    vector<int> sum( A.size(), 0 );
    sum[0] = A[0];
    for( int i=1; i<A.size(); i++ ){
        sum[i] = A[i] + sum[i-1];
    }

    unordered_map<int, int> sumMap;     // sum -> index map
    for( int i=0; i<sum.size(); i++ ){

        if( sum[i] == 0 ){
            if( i - 0 > ansJ - ansI ){
                ansI = 0;
                ansJ = i;
            } else if( i - 0 == ansJ - ansI ){
                if( 0 < ansI ){
                    ansI = 0;
                    ansJ = i;
                }
            }
        }

        if( sumMap.find( sum[i] ) != sumMap.end() ){

            // found a duplicate
            int indexI = sumMap.find( sum[i] )->second + 1;
            int indexJ = i;

            cout<<"indexI: "<<indexI<<endl;
            cout<<"indexJ: "<<indexJ<<endl<<endl;

//            if( indexI > 0 ){

                if( indexJ - indexI > ansJ - ansI ){
                    ansI = indexI;
                    ansJ = indexJ;
                } else if( indexJ - indexI == ansJ - ansI ){
                    if( indexI < ansI ){
                        ansI = indexI;
                        ansJ = indexJ;
                    }
                }
//            }

            cout<<"ansI: "<<ansI<<endl;
            cout<<"ansJ: "<<ansJ<<endl<<endl;

        } else {
            pair<int,int> pair1( sum[i], i );
            cout<<"sum[i]: "<<sum[i]<<endl;
            cout<<"i: "<<i<<endl<<endl;
            sumMap.insert( pair1 );
        }
    }

    if( ansI != A.size() ){
        for( int i=ansI; i<=ansJ; i++ ){
            ans.push_back( A[i] );
        }
    }

    return ans;
}

int main() {

//    vector<int> A = { 1 ,2 ,-2 ,4 ,-4 };  // 2 -2 4 -4
//    vector<int> A = { 1, 2, -3, 4, -2, -2 };    // entire thing
    vector<int> A = { -19, 8, 2, -8, 19, 5, -2, -23 };        // empty
    vector<int> Ans = lszero( A );
    printIntVector( Ans );

    return 0;
}