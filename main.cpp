#include <iostream>

#include "Board.h"

using namespace std;

int main() {
    int row, col;
    cout<<"nRows: "; cin>>row; cout<<"nCols: "; cin>>col;

    Board b(row, col);


    /*cout << "nr blocos: " << b.getBlocks().size() << endl;
for(int i=0;i<b.getBlocks().size();i++) {
    cout << "Char: " << b.getBlocks()[i].first << endl;
    cout << "nr pecas bloco: " << b.getBlocks()[i].second.size() << endl;
    for (int j = 0; j < b.getBlocks()[i].second.size(); j++) {
        cout << "index: " << b.getBlocks()[i].second[j].first << "/" << b.getBlocks()[i].second[j].second << endl;
    }
}*/


    /*TESTES*/


    //Reflexion right
  /*  b.setPiece(1,0,'a');
    b.setPiece(3,2, 'a');
    b.setPiece(3,1,'a');
    b.setPiece(6,0,'a');
    b.defineBlocks();
    b.printBoard();
    b.reflexionBlockRight(1,0);
    b.printBoard();*/

    //Reflexion left
    /*b.setPiece(1,5,'a');
    b.setPiece(6,5,'a');
    b.setPiece(3,4,'a');
    b.setPiece(3,3,'a');
    b.defineBlocks();
    b.printBoard();
    b.reflexionBlockLeft(1,5);
    b.printBoard();*/


    //Reflextion up
    b.setPiece(6,1,'a');
    b.setPiece(6,6,'a');
    b.setPiece(5,3,'a');
    b.setPiece(4,3,'a');
    b.defineBlocks();
    b.printBoard();
    b.reflexionBlockUp(4,3);
    b.printBoard();

    //Reflexion down
    /*b.setPiece(0,1,'a');
    b.setPiece(0,6,'a');
    b.setPiece(1,3,'a');
    b.setPiece(2,3,'a');
    b.defineBlocks();
    b.printBoard();
    b.reflexionBlockDown(0,1);
    b.printBoard();*/
}
