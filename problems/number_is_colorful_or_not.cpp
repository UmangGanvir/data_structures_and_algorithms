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

bool ans = true;

void generateSubStrings( vector<int>& curr, int index, vector<int> number, unordered_map<int,bool>& productMap ){

    if( !ans )
        return;

    if( index >= number.size() ){

        if( curr.size() == 0 )
            return;

        int product = 1;
        for( int i=0; i<curr.size(); i++ ){
            product *= curr[i];
        }

//        printIntVector( curr );
//        cout<<"product: "<<product<<endl;

        if( productMap.find( product ) != productMap.end() )
            ans = false;
        else {
            pair<int, bool> pair1( product, true );
            productMap.insert( pair1 );
        }
        return;
    }

    // ignore current number
    generateSubStrings( curr, index+1, number, productMap );

    // include current number
    if( curr.size() > 0 )
        if( number[ curr.size() ] != number[index] )
            return;
    curr.push_back( number[index] );
    generateSubStrings( curr, index+1, number, productMap );
    curr.pop_back();

}

int colorful( int A ){

    if( A == 0 )
        return 1;

    ans = true;

    vector<int> numbers;
    int tempA = A;
    while( tempA > 0 ){
        numbers.push_back( tempA%10 );
        tempA /= 10;
    }
    for( int i=0; i<numbers.size()/2; i++ )
        swap( numbers[i], numbers[ numbers.size() - 1 - i ] );

    vector<int> curr;
    unordered_map<int,bool> productMap;
    generateSubStrings( curr, 0, numbers, productMap );
    return ans ? 1 : 0;
}

int main() {

//    int A = 236; // 0
//    int A = 0;      // 1
//    int A = 2360;       // 0
    int A = 263;
    cout<<"Ans: "<<colorful( A )<<endl;

    return 0;
}