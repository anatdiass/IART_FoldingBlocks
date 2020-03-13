#include "Board.h"

/*CONSTRUCTOR*/
Board::Board(int nRows, int nCols) : nRows(nRows), nCols(nCols) {
    createEmptyBoard();
}

/*BUILD BOARD*/
void Board::createEmptyBoard() {
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            board[i][j] = " ";
        }
    }
}

/*PRINT BOARD*/
void Board::printBorderCell() {
    cout << "_____.";
}

void Board::printBorderLines() {
    cout << ".";
    for (int i=0; i<nCols; i++){
        printBorderCell();
    }
}

void Board::printHorizontalNumbers() {
    cout << "\n ";
    for(int i=0;i<nCols;i++){
        cout << "  "<<i+1<<"   ";
    }
    cout << "\n";
}

void Board::printBoard() {
    printHorizontalNumbers();
    printBorderLines();
    for(int i=0;i<nRows;i++){

        cout<<"\n|";

        for(int j=0;j<nCols-1;j++){
            cout << "  "<< board[i][j]<<"  |";
        }

        //Print last column w/numbers
        cout << "  " << board[i][nCols-1] <<"   |\t" << i+1;

        cout << "\n";
        printBorderLines();
        cout << "\n";
    }
}

/*MANAGE BOARD*/
void Board::changeCell(int x, int y, string input){
    if(x>0 && y>0)
        board[y-1][x-1]=input;
}



