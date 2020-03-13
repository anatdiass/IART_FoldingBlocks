#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iostream>
using namespace std;

class Board {
public:
    string board[100][100];

    Board(int nRows, int nCols);

    void createEmptyBoard();
    void printBorderCell();
    void printBorderLines();
    void printHorizontalNumbers();
    void printBoard();
    void changeCell(int x, int y, string input);

private:
    int nRows;
    int nCols;
};


#endif //UNTITLED_BOARD_H
