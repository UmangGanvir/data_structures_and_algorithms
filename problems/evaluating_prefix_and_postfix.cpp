#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int evaluate_postfix_expression( string exp ){
    stack<int> integers;
    for( int i=0; i<exp.length(); i++ ){

        if( (int)exp[i] >= 48 && (int)exp[i] <= 57 ){

            // Integer

            integers.push( (int)exp[i] - 48 );
        } else {

            // Operator

            int operand2 = integers.top();
            integers.pop();
            int operand1 = integers.top();
            integers.pop();

            if( string( 1, exp[i] ) == "/" ){
                integers.push( operand1 / operand2 );
            } else if( string( 1, exp[i] ) == "*" ){
                integers.push( operand1 * operand2 );
            } else if( string( 1, exp[i] ) == "+" ){
                integers.push( operand1 + operand2 );
            } else if( string( 1, exp[i] ) == "-" ){
                integers.push( operand1 - operand2 );
            }

        }
    }
    return integers.top();
}

int evaluate_prefix_expression( string exp ){
    stack<int> integers;
    for(int i= (int) (exp.length() - 1); i >= 0; i-- ){

        if( (int)exp[i] >= 48 && (int)exp[i] <= 57 ){

            // Integer

            integers.push( (int)exp[i] - 48 );
        } else {

            // Operator

            int operand1 = integers.top();
            integers.pop();
            int operand2 = integers.top();
            integers.pop();

            if( string( 1, exp[i] ) == "/" ){
                integers.push( operand1 / operand2 );
            } else if( string( 1, exp[i] ) == "*" ){
                integers.push( operand1 * operand2 );
            } else if( string( 1, exp[i] ) == "+" ){
                integers.push( operand1 + operand2 );
            } else if( string( 1, exp[i] ) == "-" ){
                integers.push( operand1 - operand2 );
            }

        }

    }
    return integers.top();
}

int main() {

    string postfixExpression = "23*54*+9-";     // ans  = 17

    cout<<"postfix evaluation of expression: ( "<<postfixExpression<<" ) ";
    cout<<"= "<<evaluate_postfix_expression( postfixExpression )<<endl;



    string prefixExpression = "-+*23*549";     // ans  = 17

    cout<<"prefix evaluation of expression: ( "<<prefixExpression<<" ) ";
    cout<<"= "<<evaluate_prefix_expression( prefixExpression )<<endl;

    return 0;
}