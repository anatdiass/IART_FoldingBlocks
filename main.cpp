#include <iostream>

#include "Board.h"

using namespace std;

int main() {
    int row, col;
    cout<<"nRows: "; cin>>row; cout<<"nCols: "; cin>>col;

    Board b(row, col);


    /*TESTES*/

    /*
    b.setPiece(2,2,'a');
    b.printBoard();


    int choice;
    cout << "1-reflexion right\n";
    cout << "2-reflexion left\n";
    cout << "3-reflexion up\n";
    cout << "4-reflexion down\n";
    cout << "choice: ";cin>>choice;

    switch(choice){
        case 1:
            b.reflexionRight(2,2);
            break;
        case 2:
            b.reflexionLeft(2,2);
            break;
        case 3:
            b.reflexionUp(2,2);
            break;
        case 4:
            b.reflexionDown(2,2);
            break;
    }
*/

    b.printBoard();

    b.setPiece(1,0,'a');
    b.setPiece(3,2, 'a');
    b.setPiece(3,1,'a');
    b.setPiece(6,0,'a');
    b.printBoard();
    b.defineBlocks();

    /*cout << "nr blocos: " << b.getBlocks().size() << endl;
    for(int i=0;i<b.getBlocks().size();i++) {
        cout << "Char: " << b.getBlocks()[i].first << endl;
        cout << "nr pecas bloco: " << b.getBlocks()[i].second.size() << endl;
        for (int j = 0; j < b.getBlocks()[i].second.size(); j++) {
            cout << "index: " << b.getBlocks()[i].second[j].first << "/" << b.getBlocks()[i].second[j].second << endl;
        }
    }*/

    b.reflexionBlockRight(3,2);
    b.printBoard();
}
