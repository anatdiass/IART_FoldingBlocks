#include <iostream>

#include "Board.h"

using namespace std;

int main() {
    int row, col;
    cout<<"nRows: "; cin>>row; cout<<"nCols: "; cin>>col;

    Board b(row, col);

    b.printBoard();
    b.changeCell(2,3,"A");
    b.printBoard();
}
