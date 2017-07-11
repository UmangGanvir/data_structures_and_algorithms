#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    cout<<"Printing vector of int vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void generateAllCombinationSums(
        vector<int>& currVec, int& currSum, int startIdx,
        const vector<int>& candidates, int& requiredSum, vector<vector<int>>& ans
){

    if( currSum == requiredSum ){
        ans.push_back( currVec );
        return;
    }

    if( currSum > requiredSum ){
        return;
    }

    for( int i=startIdx; i<candidates.size(); i++ ){

        int currElem = candidates[i];

        currVec.push_back( currElem );
        currSum += currElem;

        generateAllCombinationSums( currVec, currSum, i, candidates, requiredSum, ans );

        currVec.pop_back();
        currSum -= currElem;
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {

    sort( A.begin(), A.end() );

    vector<int> noDuplicateA( 1, A[0] );
    for( int i=1; i<A.size(); i++ ){
        if( A[i] != noDuplicateA[ noDuplicateA.size() - 1 ] )
            noDuplicateA.push_back( A[i] );
    }

    vector<vector<int>> ans;
    vector<int> currVec;
    int currSum = 0;

    generateAllCombinationSums( currVec, currSum, 0, noDuplicateA, B, ans );
    sort( ans.begin(), ans.end() );
    return ans;
}

int main() {

//    vector<int> A = { 2, 3, 6, 7 };
//    int B = 7;
//    printVectorOfVectorInt( combinationSum( A, B ) );

    vector<int> A = { 8, 10, 6, 11, 1, 16, 8 };
    int B = 28;
    printVectorOfVectorInt( combinationSum( A, B ) );

    return 0;
}