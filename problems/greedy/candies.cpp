#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool ratingCompFunc( pair<int,int> a, pair<int,int> b ){
    return a.first < b.first;
}

int candy( vector<int> &ratings ){

    unsigned long int n = ratings.size();

    vector<pair<int,int>> sortedRatingIndexPairs;
    for( int i=0; i<n; i++ ){
        pair<int,int> pair1( ratings[i], i );
        sortedRatingIndexPairs.push_back( pair1 );
    }

    sort( sortedRatingIndexPairs.begin(), sortedRatingIndexPairs.end(), ratingCompFunc );

    vector<int> candies( n, 1 );
    for( int i=0; i<n; i++ ){

        int rating = sortedRatingIndexPairs[i].first;
        int idx = sortedRatingIndexPairs[i].second;

        if( idx-1 >= 0 ){
            // left neighbor
            if( ratings[idx-1] < ratings[idx] ){
                candies[idx] = max( candies[idx], 1 + candies[idx-1] );
            }
        }

        if( idx+1 < n ){
            // right neighbor
            if( ratings[idx+1] < ratings[idx] ){
                candies[idx] = max( candies[idx], 1 + candies[idx+1] );
            }
        }

    }

    int totalCandies = 0;
    for( int i=0; i<n; i++ ){
        totalCandies += candies[i];
    }
    return totalCandies;
}

int main() {

    vector<int> ratings = { 1, 2 };
    cout<<"Ans: "<<candy( ratings )<<endl;

    return 0;
}