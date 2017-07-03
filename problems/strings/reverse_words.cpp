#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void reverseString( string& A, int startIdx, int endIdx ){
    while( startIdx <= endIdx ){
        swap( A[startIdx], A[endIdx] );
        startIdx++;
        endIdx--;
    }
}

void reverseWords(string& A) {

    unsigned long int n = A.size();

    reverseString(A, 0, (int) (n - 1));

    int startIdx = 0;
    int endIdx = 0;

    while( startIdx < n-1 ){

        while( startIdx < n && A[startIdx] == ' ' ){
            startIdx++;
        }

        while( endIdx < n-1 && A[endIdx+1] != ' ' ){
            endIdx++;
        }

        reverseString( A, startIdx, endIdx );
        startIdx = endIdx+1;
        endIdx = startIdx;
    }
}

int main() {

    string A = "the sky is blue";
    reverseWords( A );
    cout<<"Ans: "<<A<<endl;

    return 0;
}