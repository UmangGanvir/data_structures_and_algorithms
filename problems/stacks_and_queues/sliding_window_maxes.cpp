#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void printDeque( deque<pair<int,int>> deque1 ){
    cout<<endl;
    cout<<"Deque: "<<endl;
    for( auto it = deque1.begin(); it != deque1.end(); it++ ){
        cout<<it->first<<"("<<it->second<<") ";
    }
    cout<<endl;
}

vector<int> slidingMaximum(const vector<int> &A, int B) {

    deque<pair<int,int>> deque1;        // number, index
    vector<int> ans;

    /*
     * initialize deque
     */

    // 0 - find (rightmost) max in window
    int curr_max = numeric_limits<int>::min();
    int curr_max_idx = -1;

    for( int i=0; i<B && i < A.size(); i++ ){
        if( A[i] >= curr_max ){
            curr_max = A[i];
            curr_max_idx = i;
        }
    }

    // 1 - insert all elements except max in deque
    for( int i=0; i<B && i < A.size(); i++ ){

        if( i != curr_max_idx ){
            deque1.push_back({ A[i], i });
        }
    }

    // 2 - insert max in deque in the front
    deque1.push_front({ curr_max, curr_max_idx });
    ans.push_back( curr_max );
//    printDeque( deque1 );

    /*
     * Algorithm
     * - maintain elem at the front as the curr max of the window
     * */

    for( int i=B; i < A.size(); i++ ){

        int curr_elem = A[i];

        if( curr_elem < deque1.front().first ){

            deque1.push_back({ curr_elem, i });

            // Check if front element has to be removed
            // reset first as the highest elem
            // O( 1 ) amortized time

            while( i - B >= deque1.front().second ){

                deque1.erase( deque1.begin() );

                int temp_max = numeric_limits<int>::min();
                int temp_max_idx = -1;
                for( auto it = deque1.begin(); it != deque1.end(); it++ ){
                    if( it->first > temp_max ){
                        temp_max = it->first;
                        temp_max_idx = it->second;
                    }
                }

                auto itDelete = deque1.begin();
                for( ; itDelete != deque1.end(); itDelete++ ){
                    if( itDelete->first == temp_max ){
                        break;
                    }
                }

                deque1.erase( itDelete );
                deque1.push_front({ temp_max, temp_max_idx });
            }

        } else {
            deque1.clear();
            deque1.push_back({ curr_elem, i });
        }


        ans.push_back( deque1.front().first );

//        printDeque( deque1 );

    }
    return ans;
}

int main() {

//    vector<int> A = { 1, 3, -1, -3, 5, 3, 6, 7 };
//    int w = 3;
//    printIntVector( slidingMaximum( A, w ) );         // 3 3 5 5 6 7

//    vector<int> A = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//    int w = 2;
//    printIntVector( slidingMaximum( A, w ) );           // 10 9 8 7 6 5 4 3 2

//    vector<int> A = { 648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368 };
//    int w = 9;
//    printIntVector( slidingMaximum( A, w ) );           // 745 745 775 775 876 876 876 876 876 876 876 951 951 951 951 951 951 951 951 951 882 882 882 882 935 935 935 935 935 935 935 935 935 892 892 892 900 900 900 937 937 937

    vector<int> A = { 90, 943, 777, 658, 742, 559, 623, 263, 880, 176, 354, 434, 699, 501, 551, 821, 563, 974, 701, 479, 238, 87, 61, 910, 204, 534, 369, 845, 566, 19, 939, 87, 708, 323, 662, 32, 655, 835, 67, 360, 550, 173, 488, 420, 680, 805, 630, 48, 791, 991, 791, 819, 772, 228, 123, 303, 642, 780, 115, 89, 919, 830, 271, 853, 588, 249, 20, 940, 851, 749, 340, 587, 235, 106, 125, 32, 319, 590, 354, 751, 761, 564, 484, 51, 202, 370, 216, 130, 146, 632 };
    int w = 6;
    printIntVector( slidingMaximum( A, w ) );           // 943 943 777 880 880 880 880 880 880 699 821 821 974 974 974 974 974 974 910 910 910 910 910 910 845 939 939 939 939 939 939 708 835 835 835 835 835 835 550 680 805 805 805 805 991 991 991 991 991 991 819 819 780 780 780 919 919 919 919 919 919 853 940 940 940 940 940 940 851 749 587 587 590 590 751 761 761 761 761 761 761 564 484 370 632

    return 0;
}