#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iostream>
#include <vector>

using namespace std;

class Board {
public:
private:
    int nRows;
    int nCols;
    vector<vector<char>> board;
public:

    Board(int nRows, int nCols);

    void createEmptyBoard();
    void printBorderCell();
    void printBorderLines();
    void printHorizontalNumbers();
    void printBoard();

    void setPiece(int row, int col, char color);
    char getPieceColor(int row, int col);
    void reflexionRight(int row, int col);
    void reflexionLeft(int row, int col);
    void reflexionUp(int row, int col);
    void reflexionDown(int row, int col);


};


#endif //UNTITLED_BOARD_H
