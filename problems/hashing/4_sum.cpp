#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

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

int hash4( int a1, int a2, int a3, int a4 ){

    int largePrimeNumb = 9973;

    long long int hash = a1;
    hash *= largePrimeNumb;

    hash += a2;
    hash *= largePrimeNumb;

    hash += a3;
    hash *= largePrimeNumb;

    hash += a4;
    hash *= largePrimeNumb;

    hash = hash%( numeric_limits<int>::max() );

    return (int) hash;
}

vector<vector<int> > fourSum(vector<int> &A, int B) {

    sort( A.begin(), A.end() );

    vector<vector<int>> ans;
    unordered_map<int,vector<pair<int,int>>> sumIndicesMap;
    unordered_map<int,bool> valuesHashBoolMap;

    for( int i=0; i<A.size(); i++ ){
        for( int j=i+1; j<A.size(); j++ ){

            int sum = A[i] + A[j];
//            cout<<"i: "<<i<<", j: "<<j<<", sum: "<<sum<<endl;
            auto it = sumIndicesMap.find( B - sum );
            if( it != sumIndicesMap.end() ){

                for( int k=0; k<it->second.size(); k++ ){

                    int a = A[it->second[k].first];
                    int b = A[it->second[k].second];
                    int c = A[i];
                    int d = A[j];

//                    cout<<"a: "<<a<<", b: "<<b<<", c: "<<c<<", d: "<<d<<endl;

                    vector<int> ansRow = { a, b, c, d };

                    if(
                            i != it->second[k].first && i != it->second[k].second &&
                            j != it->second[k].first && j != it->second[k].second &&
                            A[it->second[k].second] <= A[i]
                    ) {

                        sort(ansRow.begin(), ansRow.end());

                        int hash4Val = hash4(ansRow[0], ansRow[1], ansRow[2], ansRow[3]);

                        auto it2 = valuesHashBoolMap.find(hash4Val);
                        if (it2 == valuesHashBoolMap.end()) {
                            ans.push_back( ansRow );
                            pair<int, bool> pair1(hash4Val, true);
                            valuesHashBoolMap.insert(pair1);
                        }
                    }
                }
                
            }

            auto itCurrSum = sumIndicesMap.find( sum );
            pair<int,int> pair1( i, j );
            if( itCurrSum != sumIndicesMap.end() ){

                itCurrSum->second.push_back(pair1);

            } else {

                vector<pair<int,int>> vector1( 1, pair1 );
                pair<int, vector<pair<int,int>>> pair2( sum, vector1 );
                sumIndicesMap.insert( pair2 );
            }
        }
    }

    sort( ans.begin(), ans.end() );
    return ans;
}

int main() {

    vector<int> A = { 1, 0, -1, 0, -2, 2 };
    int B = 0;
    printVectorOfVectorInt( fourSum( A, B ) );

    return 0;
}