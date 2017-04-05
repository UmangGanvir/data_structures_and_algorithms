#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

void printVectorOfVectorString( vector<vector<string>> vecOfVec ){
    cout<<"Printing vector of string vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void printStringVector( vector<string> vec ){
    cout<<"Printing string vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

long long int getFactorial( int n, vector<long long int>& factorials ){

    if( factorials[n-1] != -1 )
        return factorials[n-1];

    if( n == 1 ){
        factorials[0] = 1;
        return 1;
    }
    factorials[ n-1 ] = n * getFactorial( n-1, factorials );
    return factorials[ n-1 ];
}

void chooseNumbers( vector<int>& chosenNumbs, set<int>& unchosenNumbs, int index, int& k, vector<long long int>& factorials ){

    cout<<"index: "<<index<<endl;
    cout<<"k: "<<k<<endl;
    printIntVector( chosenNumbs );
    cout<<"unchosen numbs: "<<endl;
    for( auto it=unchosenNumbs.begin(); it != unchosenNumbs.end(); it++ ){
        cout<<*it<<" ";
    }
    cout<<endl;

    if( k == 0 )
        return;

    if( index >= chosenNumbs.size() + unchosenNumbs.size() )
        return;

    int n = (int) unchosenNumbs.size();
    long long int nMinusOneFact = n > 1 ? factorials[ n-2 ] : 1;

    cout<<"n: "<<n<<endl;
    cout<<"nMinusOneFact: "<<nMinusOneFact<<endl;

    if( k >= nMinusOneFact ){

        long long int chosenNumPosition = k/nMinusOneFact + 1;

        if( unchosenNumbs.size() >= chosenNumPosition ){
            int chosenNumb = -1;
            for( auto it=unchosenNumbs.begin(); it != unchosenNumbs.end() && chosenNumPosition > 0; it++ ){
                chosenNumb = *it;
                chosenNumPosition--;
            }
            cout<<"chosenNumb: "<<chosenNumb<<endl;

            chosenNumbs.push_back( chosenNumb );
            unchosenNumbs.erase( chosenNumb );
            k = (int) (k % nMinusOneFact);
        }
    } else {

        if( unchosenNumbs.size() > 0 ){
            int chosenNumb = *(unchosenNumbs.begin());
            cout<<"chosenNumb: "<<chosenNumb<<endl;

            chosenNumbs.push_back( chosenNumb );
            unchosenNumbs.erase( chosenNumb );
        }
    }

    cout<<endl<<endl;

    chooseNumbers( chosenNumbs, unchosenNumbs, index+1, k, factorials );
}

string getPermutation(int n, int k) {

    if( n == 0 )
        return "";

    vector<int> chosenNumbs;
    set<int> unchosenNumbs;
    for( int i=1; i<=n; i++ ){
        unchosenNumbs.insert( i );
    }

    vector<long long int> factorials( n, -1 );
    getFactorial( n, factorials );

//    printIntVector( factorials );

    cout<<"pre"<<endl;
    k--;
    cout<<"operation"<<endl;
    cout<<"k: "<<k<<endl;
    if( k > factorials[n-1] )
        k %= factorials[n-1];

    cout<<"post"<<endl;
    chooseNumbers( chosenNumbs, unchosenNumbs, 0, k, factorials );

    string str = "";
    for( int i=0; i<chosenNumbs.size(); i++ ){
        cout<<"chosenNumbs[i]: "<<chosenNumbs[i]<<endl;
        str += to_string( chosenNumbs[i] );
    }
    for( auto it=unchosenNumbs.begin(); it != unchosenNumbs.end(); it++ ){
        cout<<"unchosenNumbs[i]: "<<*it<<endl;
        str += to_string( *it );
    }
    return str;
}

int main() {

//    string A = getPermutation( 3, 4 );          // 231
//    string A = getPermutation( 3, 5 );          // 312
//    string A = getPermutation( 4, 9 );          // 2314
//    string A = getPermutation( 8, 53 );         // 12364857
    string A = getPermutation( 8, 59 );         // 12365847
//    string A = getPermutation( 1, 126000 );     // 1
//    string A = getPermutation( 100, 126000 );     // 123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919592100999897969493
    cout<<"Ans: "<<A<<endl;

    return 0;
}