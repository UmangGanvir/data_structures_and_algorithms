#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fibsum(int A) {

    vector<int> fibs;

    int fPrev = 1, fPrevPrev = 1;
    fibs.push_back( fPrevPrev );
    fibs.push_back( fPrev );

    while( fPrev < A ){
        int currFib = fPrev + fPrevPrev;
        fibs.push_back( currFib );

        fPrevPrev = fPrev;
        fPrev = currFib;
    }

    int minElemsRequired = 0;
    int ctr = (int) (fibs.size() - 1);
    while( A != 0 && ctr >= 0 ){

        if( A - fibs[ctr] >= 0 ){
            A -= fibs[ctr];
            minElemsRequired++;
        }
        ctr--;

    }
    return minElemsRequired;
}

int main() {

    int A = 4;
    cout<<"Ans: "<<fibsum( A )<<endl;

    return 0;
}