#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void printVector( vector<int> vec ){
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

vector<int> prevSmallerInArr(vector<int> &A) {

    vector<int> ans( A.size(), -1 );
    stack<int> stack1;

    for( int i=0; i<A.size(); i++ ){
        if( stack1.empty() ){
        } else {
            while( !stack1.empty() && stack1.top() >= A[i] ){
                stack1.pop();
            }

            if( !stack1.empty() ){
                ans[i] = stack1.top();
            }
        }
//        cout<<"A[i]: "<<A[i]<<endl;
//        cout<<"ans[i]: "<<ans[i]<<endl;
//        cout<<"stack.top(): "<<stack1.top()<<endl<<endl;
        stack1.push( A[i] );
    }
    return ans;
}

int main() {

//    vector<int> A = { 4, 5, 2, 10 };
    vector<int> A = { 39, 27, 11, 4, 24, 32, 32, 1 };


    printVector( prevSmallerInArr( A ) );

    return 0;
}