#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int singleNumber(const vector<int> &A) {

    vector<int> onesBits( 32, 0 );

    for( int i=0; i<A.size(); i++ ){

        int a = A[i];
        int ctr = 0;
        while( a > 0 ){

            if( a % 2 == 1 ){
                if( onesBits[31 - ctr] == 2 )
                    onesBits[31 - ctr] = 0;
                else
                    onesBits[31 - ctr]++;
            }
            a >>= 1;
            ctr++;
        }
    }

    int ans = 0;
    int ctr = 0;
    for( int i=31; i>=0 ; i-- ){
        ans += onesBits[i] * pow( 2, ctr );
        ctr++;
    }
    return ans;
}

int main() {

    vector<int> A = { 1, 2, 4, 3, 3, 2, 2, 3, 1, 1 };
    cout<<"Ans: "<<singleNumber( A )<<endl;

    return 0;
}