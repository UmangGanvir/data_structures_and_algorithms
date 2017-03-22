#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr( vector<int> arr ){
    for( int i=0; i<arr.size(); i++ ){
        cout<<arr[i]<<" ";
    }
}

void mergeArray( const vector<int> &left, const vector<int> &right, vector<int> &result ){

    int i=0, j=0, k=0;

    while( i < left.size() && j < right.size() ){
        if( left[i] <= right[j] ){
            result[k] = left[i];
            i++;
        } else {
            result[k] = right[j];
            j++;
        }
        k++;
    }

    while( i < left.size() ){
        result[k] = left[i];
        i++; k++;
    }

    while( j < right.size() ){
        result[k] = right[j];
        j++; k++;
    }
}


void merge_sort( vector<int> &arr ){

    if( arr.size() < 2 )
        return;

    unsigned long arrLen = arr.size();
    unsigned long midSize = (arrLen / 2);

    vector<int> left( midSize );
    for( int i=0; i<midSize; i++ )
        left[i] = arr[i];

    vector<int> right( arrLen - midSize );
    for(int i= (int) midSize; i < arrLen; i++ )
        right[i-midSize] = arr[i];

    merge_sort( left );
    merge_sort( right );
    mergeArray( left, right, arr );
}

int main() {
    vector<int> arr = { 2, 4, 1, 6, 8, 5, 3, 7 };

    merge_sort( arr );
    printArr( arr );
    return 0;
}