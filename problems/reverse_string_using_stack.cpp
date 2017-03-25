#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string reverseStringByStack( string A ){

    int n = (int) A.length();
    stack<char> chars;
    for( int i=0; i<n; i++ ){
        chars.push( A[i] );
    }

    for( int i=0; i<n; i++ ){
        A[i] = chars.top();
        chars.pop();
    }
    return A;
}

int main() {
    string a = "1234567890";
    cout<<"reversed string: "<<reverseStringByStack( a )<<endl;
    return 0;
}