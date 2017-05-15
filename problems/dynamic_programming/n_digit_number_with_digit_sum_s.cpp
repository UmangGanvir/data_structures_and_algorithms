#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

vector<int> DigitOptions = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void setDigits(
        vector<int>& currDigits, int currSetDigitIdx, int digitOptionStartIdx, int digitOptionEndIdx,
        int remainingSum, int& currentAns, unordered_map<long long int,int>& remainingSumSetDigitNumbAns
){

    if( currSetDigitIdx == currDigits.size() )
        return;

    if( currSetDigitIdx == currDigits.size() - 1 ){

        if( remainingSum == 0 ){

            currentAns++;
            currentAns %= 1000000007;
        }
        return;
    }

    if( remainingSum == 0 ){

        currentAns++;
        currentAns %= 1000000007;
        return;
    }

    long long int complexKey = remainingSum*7919;
    complexKey += currSetDigitIdx;
    complexKey *= 7919;
    auto it = remainingSumSetDigitNumbAns.find( complexKey );
    if( it != remainingSumSetDigitNumbAns.end() ){
        currentAns += it->second;
        currentAns %= 1000000007;
        return;
    }

    for( int i=digitOptionStartIdx; i<=digitOptionEndIdx; i++ ){

        if( remainingSum - DigitOptions[i] < 0 )
            break;

        currSetDigitIdx++;
        currDigits[currSetDigitIdx] = DigitOptions[i];
        remainingSum -= DigitOptions[i];

        // set next digit
        digitOptionStartIdx = 0;
        int tempAns = 0;
        setDigits(
                currDigits, currSetDigitIdx, digitOptionStartIdx, digitOptionEndIdx,
                remainingSum, tempAns, remainingSumSetDigitNumbAns
        );

        long long int complexKey1 = remainingSum*7919;
        complexKey1 += currSetDigitIdx;
        complexKey1 *= 7919;
        auto it1 = remainingSumSetDigitNumbAns.find( complexKey1 );
        if( it1 == remainingSumSetDigitNumbAns.end() ){
            pair<long long int,int> pair1( complexKey1, tempAns );
            remainingSumSetDigitNumbAns.insert(pair1);
        }

        currentAns += tempAns;
        currentAns %= 1000000007;

        // revert set digit
        currDigits[currSetDigitIdx] = -1;
        currSetDigitIdx--;

        remainingSum += DigitOptions[i];
    }

}

int solve(int A, int B) {

    vector<int> currDigits((unsigned long) A, -1 );
    int currSetDigitIdx = -1;

    int digitOptionStartIdx = 1;
    int digitOptionEndIdx = 9;

    int currentAns = 0;

    unordered_map<long long int,int> remainingSumSetDigitNumbAns;

    setDigits( currDigits, currSetDigitIdx, digitOptionStartIdx, digitOptionEndIdx, B, currentAns, remainingSumSetDigitNumbAns );

    return currentAns;
}

int main() {

//    int A = 2, B = 4;
//    cout<<"Ans: "<<solve( A, B )<<endl;

    int A = 75, B = 22;
    cout<<"Ans: "<<solve( A, B )<<endl;

    return 0;
}