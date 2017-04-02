#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
}

void printIntVector( vector<int> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {

    if (index >= S.size()) {
        result.push_back(current);
        return;
    }
    // Ignore the current index.
    generateSubsets(S, index + 1, current, result);

    // Include the current index.
    current.push_back(S[index]);
    generateSubsets(S, index + 1, current, result);
    current.pop_back();
}

vector<vector<int>> subsets(vector<int> &A) {

    vector<vector<int> > result;
    vector<int> current;
    sort(A.begin(), A.end());
    generateSubsets(A, 0, current, result);
    sort(result.begin(), result.end());
    return result;
}

int main() {

    vector<int> A = { 1, 2, 3 };
//    vector<int> A = { 15, 20, 12, 19, 4 };
    subsets( A );
    cout<<"ans: "<<endl;
    printVectorOfVectorInt( subsets( A ) );

    return 0;
}