#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_arr( vector<int> arr ){
    for( int i=0; i<arr.size(); i++ )
        cout<<arr[i]<<" ";
    cout<<endl;
}

int partition_arr( int start, int end, vector<int> &arr ){
    int pivot = arr[ end ];
    int pIndex = start;
    for( int i=start; i<=end; i++ ){
        if( arr[i] < pivot ){
            swap( arr[i], arr[pIndex] );
            pIndex++;
        }
    }
    swap( arr[end], arr[pIndex] );
    return pIndex;
}

void quick_sort( int start, int end, vector<int> &arr ){
    if( start < end ){
        int pIndex = partition_arr( start, end, arr );
        quick_sort( start, pIndex - 1, arr );
        quick_sort( pIndex + 1, end, arr );
    }
}

int main() {

    vector<int> arr = { 2, 4, 1, 6, 8, 5, 3, 7 };
    quick_sort(0, (int) arr.size() - 1, arr );
    print_arr( arr );
    return 0;
}