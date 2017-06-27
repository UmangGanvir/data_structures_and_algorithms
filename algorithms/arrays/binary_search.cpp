#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int binary_search( const vector<int> &A, int B, bool firstOccurrence ){

    int low = 0, high = (int) (A.size() - 1), mid, result = -1;

    while( low <= high ){

        mid = low + (high-low)/2;
        if( A[mid] == B ){

            result = mid;
            if( firstOccurrence )
                high = mid-1;
            else
                low = mid+1;

        } else if( B < A[mid] ){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return result;
}

void print_arr( vector<int> arr ){
    for( int i=0; i<arr.size(); i++ )
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    vector<int> A;
    for( int i=0; i<1000; i++ ){
        A.push_back(i+1);
    }

    int numb = 875;
    int index = binary_search( A, numb, true );
    cout<<"Number was at index: "<<index<<endl;

    return 0;
}