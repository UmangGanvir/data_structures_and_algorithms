#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int,int>> stack1;        // first is elem, second is min till that elem

class MinStack {
public:
    MinStack();
    void push( int a );
    void pop();
    int top();
    int getMin();
};

MinStack::MinStack() {

    stack<pair<int,int>> stack2;
    stack1.swap( stack2 );
}

void MinStack::push(int x) {
    int currMin = stack1.empty() ? x : stack1.top().second;
    if( x < currMin )
        currMin = x;
    stack1.push( make_pair( x, currMin ) );
}

void MinStack::pop() {
    if( !stack1.empty() )
        stack1.pop();
}

int MinStack::top() {
    return stack1.empty() ? -1 : stack1.top().first;
}

int MinStack::getMin() {
    return stack1.empty() ? -1 : stack1.top().second;
}



int main() {

    string A = "Umang";
//    cout<<"Ans: "<<methodName( A )<<endl;

    MinStack *minStack = new MinStack();
    minStack->push( 10 );
    minStack->push( 9 );
    minStack->getMin();
    minStack->push( 8 );
    cout<<minStack->getMin()<<endl;
    minStack->push( 7 );
    cout<<minStack->getMin()<<endl;
    minStack->push( 6 );
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->getMin()<<endl;

    return 0;
}