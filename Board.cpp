#include "Board.h"

/*CONSTRUCTOR*/
Board::Board(int nRows, int nCols) : nRows(nRows), nCols(nCols) {
    createEmptyBoard();
}

/*BUILD BOARD*/
void Board::createEmptyBoard() {
    vector<char> aux;
    for(int i=0;i<nRows;i++){
        aux.push_back(' ');
    }
    for(int j=0;j<nCols;j++){
        aux.push_back(' ');
        board.push_back(aux);
    }
}

/*PRINT BOARD*/
void Board::printBorderCell() {
    cout << "_____.";
}

void Board::printBorderLines() {
    cout << "   .";
    for (int i=0; i<nCols; i++){
        printBorderCell();
    }
}

void Board::printHorizontalNumbers() {
    cout << "\n ";
    for(int i=0;i<nCols;i++){
        cout << "     "<<i+1;
    }
    cout << "\n";
}

void Board::printBoard() {

    printHorizontalNumbers();
    printBorderLines();
    for(int i=0;i<nRows;i++){

        //Print row indice
        cout<<"\n" << i+1;
        cout << ((i + 1) < 10 ? "  |" : " |");

        //Print cell color
        for(int j=0;j<nCols;j++){
            cout << "  "<< board[i][j]<<"  |";
        }

        cout << "\n";
        printBorderLines();
        cout << "\n";
    }
}


/*MANAGE BOARD*/

void Board::setPiece(int row, int col, char color){
    if(row>0 && col>0 && row<=nRows && col<=nCols)
        board.at(row-1).at(col-1) = color;
}

char Board::getPieceColor(int row, int col) {
    if(row>0 && col>0 && row<=nRows && col<=nCols)
        return board.at(row-1).at(col-1);
    else return (char)0;
}

/*REFLEXION FUNCTIONS*/
void Board::reflexionRight(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' ' || nCols<=col)
        return;

    if(getPieceColor(row, col+1)==' ')
        setPiece(row, col+1, cellContent);
}

void Board::reflexionLeft(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' '  || col==1)
        return;

    if(getPieceColor(row, col-1)==' ')
        setPiece(row, col-1, cellContent);
}

void Board::reflexionUp(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' '  || row==1)
        return;

    if(getPieceColor(row-1,col)==' ')
        setPiece(row-1, col, cellContent);
}

void Board::reflexionDown(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' ' || nRows<=row)
        return;

    if(getPieceColor(row+1,col)==' ')
        setPiece(row+1,col,cellContent);
}



