#include <iostream>

#include "Board.h"

using namespace std;

int main() {
    int row, col;
    cout<<"nRows: "; cin>>row; cout<<"nCols: "; cin>>col;

    Board b(row, col);


    /*TESTES*/
    b.printBoard();

    /*
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

    b.printBoard();*/

    b.defineBlocks();

/*    cout << "nr blocos: " << b.getBlocks().size() << endl;
    for(int i=0;i<b.getBlocks().size();i++){
        cout << "Char: " << b.getBlocks()[i].first<<endl;
        cout << "index: " << b.getBlocks()[i].second.first << "/" << b.getBlocks()[i].second.second<<endl;
    }*/
}
