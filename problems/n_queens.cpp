#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVectorOfVectorInt( vector<vector<int>> vecOfVec ){
    cout<<"Printing vector of int vectors: "<<endl;
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
        cout<<vec[i]<<endl;
    cout<<endl;
}

void printVectorOfVectorString( vector<vector<string>> vecOfVec ){
    cout<<"Printing vector of string vectors: "<<endl;
    int n = (int) vecOfVec.size();
    for( int i=0; i<n; i++ ) {
        for (int j = 0; j < vecOfVec[i].size(); j++) {
            cout << vecOfVec[i][j] <<endl;
        }
        cout << endl<<endl;
    }
    cout<<endl;
}

void setQueenAt( vector<vector<int>>& board, int rowIndex, int colIndex ){

    int m = (int) board.size();

    board[rowIndex][colIndex]++;
    board[rowIndex][colIndex] += m;

    int startRow = -1, startCol = -1;

    // up
    startRow = rowIndex-1; startCol = colIndex;
    while( startRow >= 0 ){
        board[startRow][startCol]++;
        startRow--;
    }

//    cout<<"post up:"<<endl;
//    printVectorOfVectorInt( board );

    // up right diagonal
    startRow = rowIndex-1; startCol = colIndex+1;
    while( startRow >= 0 && startCol < m ){
        board[startRow][startCol]++;
        startRow--;
        startCol++;
    }

//    cout<<"post up right diagonal:"<<endl;
//    printVectorOfVectorInt( board );

    // right
    startRow = rowIndex; startCol = colIndex+1;
    while( startCol < m ){
        board[startRow][startCol]++;
        startCol++;
    }

//    cout<<"post right:"<<endl;
//    printVectorOfVectorInt( board );

    // down right diagonal
    startRow = rowIndex+1; startCol = colIndex+1;
    while( startRow < m && startCol < m ){
        board[startRow][startCol]++;
        startRow++;
        startCol++;
    }

//    cout<<"post down right diagonal:"<<endl;
//    printVectorOfVectorInt( board );

    // down
    startRow = rowIndex+1; startCol = colIndex;
    while( startRow < m ){
        board[startRow][startCol]++;
        startRow++;
    }

//    cout<<"post down:"<<endl;
//    printVectorOfVectorInt( board );

    // down left diagonal
    startRow = rowIndex+1; startCol = colIndex-1;
    while( startRow < m && startCol >= 0 ){
        board[startRow][startCol]++;
        startRow++;
        startCol--;
    }

//    cout<<"post down left diagonal:"<<endl;
//    printVectorOfVectorInt( board );

    // left
    startRow = rowIndex; startCol = colIndex-1;
    while( startCol >= 0 ){
        board[startRow][startCol]++;
        startCol--;
    }

//    cout<<"post left:"<<endl;
//    printVectorOfVectorInt( board );

    // up left
    startRow = rowIndex-1; startCol = colIndex-1;
    while( startRow >= 0 && startCol >= 0 ){
        board[startRow][startCol]++;
        startRow--;
        startCol--;
    }

//    cout<<"post up left:"<<endl;
//    printVectorOfVectorInt( board );
}

void revertQueenAt( vector<vector<int>>& board, int rowIndex, int colIndex ){

    int m = (int) board.size();

    board[rowIndex][colIndex]--;
    board[rowIndex][colIndex] -= m;

    int startRow = -1, startCol = -1;

    // up
    startRow = rowIndex-1; startCol = colIndex;
    while( startRow >= 0 ){
        board[startRow][startCol]--;
        startRow--;
    }

//    cout<<"post up:"<<endl;
//    printVectorOfVectorInt( board );

    // up right diagonal
    startRow = rowIndex-1; startCol = colIndex+1;
    while( startRow >= 0 && startCol < m ){
        board[startRow][startCol]--;
        startRow--;
        startCol++;
    }

//    cout<<"post up right diagonal:"<<endl;
//    printVectorOfVectorInt( board );

    // right
    startRow = rowIndex; startCol = colIndex+1;
    while( startCol < m ){
        board[startRow][startCol]--;
        startCol++;
    }

//    cout<<"post right:"<<endl;
//    printVectorOfVectorInt( board );

    // down right diagonal
    startRow = rowIndex+1; startCol = colIndex+1;
    while( startRow < m && startCol < m ){
        board[startRow][startCol]--;
        startRow++;
        startCol++;
    }

//    cout<<"post down right diagonal:"<<endl;
//    printVectorOfVectorInt( board );

    // down
    startRow = rowIndex+1; startCol = colIndex;
    while( startRow < m ){
        board[startRow][startCol]--;
        startRow++;
    }

//    cout<<"post down:"<<endl;
//    printVectorOfVectorInt( board );

    // down left diagonal
    startRow = rowIndex+1; startCol = colIndex-1;
    while( startRow < m && startCol >= 0 ){
        board[startRow][startCol]--;
        startRow++;
        startCol--;
    }

//    cout<<"post down left diagonal:"<<endl;
//    printVectorOfVectorInt( board );

    // left
    startRow = rowIndex; startCol = colIndex-1;
    while( startCol >= 0 ){
        board[startRow][startCol]--;
        startCol--;
    }

//    cout<<"post left:"<<endl;
//    printVectorOfVectorInt( board );

    // up left
    startRow = rowIndex-1; startCol = colIndex-1;
    while( startRow >= 0 && startCol >= 0 ){
        board[startRow][startCol]--;
        startRow--;
        startCol--;
    }

//    cout<<"post up left:"<<endl;
//    printVectorOfVectorInt( board );
}

void setQueenPosition( vector<vector<int>>& board, int boardSize, int rowIndexPlusColIndex, int n, vector<vector<string>>& ans ){

    if( n == 0 ){

        vector<string> ansString((unsigned long) boardSize, string((unsigned long) boardSize, '.') );
        for( int i=0; i<boardSize; i++ ){
            for( int j=0; j<boardSize; j++ ){
                if( board[i][j] > boardSize )
                    ansString[i][j] = 'Q';
            }
        }
        ans.push_back( ansString );
        return;
    }

    int ctr = rowIndexPlusColIndex;

    while( ctr < boardSize*boardSize ){

        int i = (ctr/boardSize);
        int j= (ctr%boardSize);

        /*
         * This is the gist of the problem! :)
         * */
        if( i > boardSize - n )
            break;

        if( board[i][j] == 0 ){

            setQueenAt( board, i, j );
            setQueenPosition( board, boardSize, (i+1)*boardSize, n-1, ans );
            revertQueenAt( board, i, j );
        }
        ctr++;
    }
}

vector<vector<string>> solveNQueens( int A ){

    vector<vector<string>> ans;
    vector<vector<int>> board( A, vector<int>( A, 0 ) );

    /*
     * . -> Empty
     * - -> unsafe place
     * Q -> Queen already placed
     * */

    setQueenPosition( board, A, 0, A, ans );
    return ans;
}

int main() {

//    vector<vector<string>> board = solveNQueens( 4 );
    vector<vector<string>> board = solveNQueens( 10 );
    printVectorOfVectorString( board );

    return 0;
}