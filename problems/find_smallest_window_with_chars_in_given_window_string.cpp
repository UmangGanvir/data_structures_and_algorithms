#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindow(string S, string T) {

    unordered_map<char, int> TMap;
    for(int i=0; i<T.length(); i++){
        auto it = TMap.find( T[i] );
        if( it != TMap.end() )
            it->second++;
        else {
            pair<char,int> pair1( T[i], 1 );
            TMap.insert( pair1 );
        }
    }

    int Slen = (int) S.length();
    int Tlen = (int) T.length();

    int requiredCharCount = Tlen;
    int ansStartIdx = -1, ansEndIdx = -1;

    int ctr = -1;
    int currStartIdx = -1;
    int nextStartIdx = -1;
    int ctrSpecificRequiredCharCount = requiredCharCount;

    for( int i=0; i<Slen; i++ ){
        if( TMap.find( S[i] ) != TMap.end() ){
            currStartIdx = i;
            ctr = i;
            break;
        }
    }

    if( currStartIdx == -1 )
        return "";

    while( ctr < Slen ){

        auto it = TMap.find( S[ctr] );
        if( it != TMap.end() ){

            if( ansStartIdx == -1 )
                ansStartIdx = ctr;

            if( nextStartIdx == -1 && ctr != currStartIdx )
                nextStartIdx = ctr;

            if( it->second > 0 ){
                ctrSpecificRequiredCharCount--;
            }
            it->second--;
        } else {
//            pair<char,int> pair1( S[ctr], 0 );
//            TMap.insert( pair1 );
        }

        while( ctrSpecificRequiredCharCount == 0 ){

            // set ansEndIdx
            if( ansEndIdx == -1 )
                ansEndIdx = ctr;
            else {

                if( ansEndIdx - ansStartIdx > ctr - currStartIdx ){
                    ansStartIdx = currStartIdx;
                    ansEndIdx = ctr;
                }
            }

            // reset value for removed elem in map
            auto it1 = TMap.find( S[currStartIdx] );
            if( it1 != TMap.end() ){
                it1->second++;
                if( it1->second > 0 )
                    ctrSpecificRequiredCharCount++;
            }

            if( nextStartIdx != -1 )
                currStartIdx = nextStartIdx;
            else
                currStartIdx++;

            // update next start index
            if( nextStartIdx + 1 < Slen ){
                nextStartIdx++;
                auto it2 = TMap.find( S[nextStartIdx] );
                while( it2 == TMap.end() ){
                    nextStartIdx++;
                    if( nextStartIdx == Slen )
                        break;
                    it2 = TMap.find( S[nextStartIdx] );
                }
            } else
                break;
        }

        ctr++;
    }

    if( ansStartIdx == -1 || ansEndIdx == -1 )
        return "";

    return S.substr( ansStartIdx, ansEndIdx - ansStartIdx + 1 );
}

int main() {

//    cout<<"Ans: "<<minWindow( "ADOBECODEBANC", "ABC" )<<endl;
//    cout<<"Ans: "<<minWindow( "ADOBECODEBANC", "ABCK" )<<endl;
//    cout<<"Ans: "<<minWindow( "A", "A" )<<endl;
//    cout<<"Ans: "<<minWindow(
//            "xiEjBOGeHIMIlslpQIZ6jERaAVoHUc9Hrjlv7pQpUSY8oHqXoQYWWll8Pumov89wXDe0Qx6bEjsNJQAQ0A6K21Z0BrmM96FWEdRG69M9CYtdBOrDjzVGPf83UdP3kc4gK0uHVKcPN4HPdccm9Qd2VfmmOwYCYeva6BSG6NGqTt1aQw9BbkNsgAjvYzkVJPOYCnz7U4hBeGpcJkrnlTgNIGnluj6L6zPqKo5Ui75tC0jMojhEAlyFqDs7WMCG3dmSyVoan5tXI5uq1IxhAYZvRQVHtuHae0xxwCbRh6S7fCLKfXeSFITfKHnLdT65K36vGC7qOEyyT0Sm3Gwl2iXYSN2ELIoITfGW888GXaUNebAr3fnkuR6VwjcsPTldQSiohMkkps0MH1cBedtaKNoFm5HbH15kKok6aYEVsb6wOH2w096OwEyvtDBTQwoLN87JriLwgCBBavbOAiLwkGGySk8nO8dLHuUhk9q7f0rIjXCsQeAZ1dfFHvVLupPYekXzxtWHd84dARvv4Z5L1Z6j8ur2IXWWbum8lCi7aErEcq41WTo8dRlRykyLRSQxVH70rUTz81oJS3OuZwpI1ifBAmNXoTfznG2MXkLtFu4SMYC0bPHNctW7g5kZRwjSBKnGihTY6BQYItRwLUINApd1qZ8W4yVG9tnjx4WyKcDhK7Ieih7yNl68Qb4nXoQl079Vza3SZoKeWphKef1PedfQ6Hw2rv3DpfmtSkulxpSkd9ee8uTyTvyFlh9G1Xh8tNF8viKgsiuCZgLKva32fNfkvW7TJC654Wmz7tPMIske3RXgBdpPJd5BPpMpPGymdfIw53hnYBNg8NdWAImY3otYHjbl1rqiNQSHVPMbDDvDpwy01sKpEkcZ7R4SLCazPClvrx5oDyYolubdYKcvqtlcyks3UWm2z7kh4SHeiCPKerh83bX0m5xevbTqM2cXC9WxJLrS8q7XF1nh",
//            "dO4BRDaT1wd0YBhH88Afu7CI4fwAyXM8pGoGNsO1n8MFMRB7qugS9EPhCauVzj7h"
//    )<<endl;
    cout<<"Ans: "<<minWindow(
            "z3OyxTp7j3usoz2l0zmr8tJCocoNUvL1cVTWuroYKTluh60TsRvR8jNjiStkt2FNRxPtUn4ZTWSeqgClbFyPWqUHTaSRC5cY5JPVAW25IGusbMaRYmPWUOswP0QnU1BFYldSoDEV59efpkUXI6BQ6vnTAB4",
            "m"
    )<<endl;

    return 0;
}