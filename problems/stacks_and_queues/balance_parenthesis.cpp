#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int isValidExpression( string A ){

    int n = (int) A.length();
    stack<char> chars;
    for( int i=0; i<n; i++ ){
        if( A[i] == '(' || A[i] == '{' || A[i] == '[' ){
            chars.push( A[i] );
        } else {

            if( A[i] == ')' ){
                if( chars.empty() || chars.top() != '(' )
                    return 0;
                else {
                    chars.pop();
                }
            } else if( A[i] == '}' ){
                if( chars.empty() || chars.top() != '{' )
                    return 0;
                else {
                    chars.pop();
                }
            } else if( A[i] == ']' ){
                if( chars.empty() || chars.top() != '[' )
                    return 0;
                else {
                    chars.pop();
                }
            }
        }
    }

    return chars.empty() ? 1 : 0;
}

int main() {
//    string a = "(({{[[]]}}))";
    string a = "])";
    cout<<"valid: "<<isValidExpression( a )<<endl;
    return 0;
}