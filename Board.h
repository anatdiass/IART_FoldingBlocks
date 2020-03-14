#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iostream>
using namespace std;

class Board {
public:
    int getNRows() const;

    int getNCols() const;

    string board[100][100];

    /*---REGULAR BOARDS---*/
    Board(int nRows, int nCols);

    void createEmptyBoard();
    void printBorderCell();
    void printBorderLines();
    void printHorizontalNumbers();
    void printBoard();
    string checkCellContent(int x, int y);
    void changeCell(int x, int y, string input);
    void reflexionRight(int x, int y);
    void reflexionLeft(int x, int y);
    void reflexionUp(int x, int y);
    void reflexionDown(int x, int y);

private:
    int nRows;
    int nCols;
};


#endif //UNTITLED_BOARD_H
