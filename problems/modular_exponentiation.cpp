#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int modular_exponentiation( int A, int B, int C ){

    cout<<"modular_exponentiation - A: "<<A<<", B: "<<B<<", C: "<<C<<endl;

    if( B == 0 )
        return 1%C;

    if( C == 1 )
        return 0;

    if( A == 1 )
        return 1;

    if( A < 0 ){
        A = ( A % C );
        A += C;
    } else if ( A > C ){
        A = ( A % C );
    }

    if( B % 2 == 0 ){
        long long int x = modular_exponentiation( A, B/2, C );
        long long int ans = (int) ((x*x) % C);
        return (int)ans;
    } else {
        long long int y = modular_exponentiation( A, B-1, C );
        long long int ans = ( ( A%C ) * y )%C;
        return (int)ans;
    }
}

int main() {

    int A = 71045970;
    int B = 41535484;
    int C = 64735492;

//    int A = -43;
//    int B = 3;
//    int C = 5;

//    int A = 213;
//    int B = 231;
//    int C = 1;

    int ans = modular_exponentiation( A, B, C );
    while( ans < 0 ){
        ans += C;
    }
    cout<<"ans: "<<ans<<endl;

    return 0;
}