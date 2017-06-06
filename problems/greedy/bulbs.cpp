#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bulbs( vector<int> &A ){

    int count = 0;
    bool btnPressed = false;

    int i=0;
    while( i < A.size() ){

        if( A[i] == 1 ){

            if( btnPressed ){
                count++;
                btnPressed = !btnPressed;
            }
        } else {

            if( !btnPressed ){
                count++;
                btnPressed = !btnPressed;
            }
        }

        i++;
    }
    return count;
}

int main() {

    vector<int> A = { 0, 1, 0, 1 };
    cout<<"Ans: "<<bulbs( A )<<endl;

    return 0;
}