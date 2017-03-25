#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int evalReversePolishNotation(vector<string> &A) {

    int n = (int) A.size();
    stack<int> stack1;

    for( int i=0; i<n; i++ ){

        if( A[i] == "*" ){

            int operand2 = stack1.top();
            stack1.pop();

            int operand1 = stack1.top();
            stack1.pop();

            stack1.push( operand1 * operand2 );

        } else if( A[i] == "/" ){

            int operand2 = stack1.top();
            stack1.pop();

            int operand1 = stack1.top();
            stack1.pop();

            stack1.push( operand1 / operand2 );

        } else if( A[i] == "+" ){

            int operand2 = stack1.top();
            stack1.pop();

            int operand1 = stack1.top();
            stack1.pop();

            stack1.push( operand1 + operand2 );

        } else if( A[i] == "-" ){

            int operand2 = stack1.top();
            stack1.pop();

            int operand1 = stack1.top();
            stack1.pop();

            stack1.push( operand1 - operand2 );

        } else {

            // Number
            stack1.push( stoi( A[i] ) );

        }
    }

    return stack1.top();
}

int main() {

//    vector<string> A = { "2", "1", "+", "3", "*" };             // 9
    vector<string> A = { "4", "13", "5", "/", "+" };              // 6
    cout<<"Ans: "<<evalReversePolishNotation( A )<<endl;

    return 0;
}