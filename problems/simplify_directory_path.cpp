#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string simplifyDirectoryPath( string A ){

    int n = (int) A.length();
    stack<string> paths;
    bool prevWasDot = false;

    for( int i=0; i<n; i++ ){

        if( A[i] != '/' && A[i] != '.' ){
            string path="";
            while( A[i] != '/' && A[i] != '.' && i < n ){
                path += string( 1, A[i] );
                i++;
            }
            paths.push( path );
            prevWasDot = false;
            continue;
        }

        if( A[i] == '/' ){
            prevWasDot = false;
            continue;
        }

        if( A[i] == '.' ){

            if( prevWasDot ){
                if( !paths.empty() )
                    paths.pop();
                prevWasDot = false;
            } else {
                prevWasDot = true;
            }
            continue;
        }
    }

    stack<string> reversePaths;
    while( !paths.empty() ){
        reversePaths.push( paths.top() );
        paths.pop();
    }

    string ans = "/";
    while( !reversePaths.empty() ){
        ans += reversePaths.top();
        reversePaths.pop();

        if( !reversePaths.empty() )
            ans += "/";
    }
    return ans;
}

int main() {

//    string A = "/a/./b/../../c/";           // "/c"
//    string A = "/var///log";           // "/var/log"
    string A = "/../";           // "/var/log"
    cout<<"Simplified Path: "<<simplifyDirectoryPath( A )<<endl;

    return 0;
}