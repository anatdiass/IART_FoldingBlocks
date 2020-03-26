#include <sstream>
#include <cstring>
#include "Game.h"

Game::Game() {
    this->board=Board();
    chooseLevel();
}

bool Game::checkVictory() {
    for(int i=0;i<board.getNumRows();i++){
        for(int j=0;j<board.getNumCols();j++){
            char cellContent = board.getPieceColor(i,j);
            if(cellContent==' ')
                return false;
        }
    }
    return true;
}

bool Game::endGame() {
    if(checkVictory() /*|| noMoreMovesAvailable*/)
        return true;

    return false;
}

void Game::level1() {
    this->board=Board(4,4);
    this->board.setPiece(3,0,'R');
}


void Game::level2(){
    this->board=Board(4,4);

    //Null cells
    board.deleteCell(0,1);
    board.deleteCell(0,2);
    board.deleteCell(1,0);
    board.deleteCell(1,3);
    board.deleteCell(2,0);
    board.deleteCell(2,3);
    board.deleteCell(3,1);
    board.deleteCell(3,2);

    board.setPiece(3,0,'A');
    board.setPiece(2,1,'A');
}

void Game::level3(){
    this->board=Board(5,4);

    board.deleteCell(0,2);
    board.deleteCell(0,3);
    board.deleteCell(4,0);
    board.deleteCell(4,1);

    board.setPiece(0,0,'V');
    board.setPiece(4,2, 'A');
}

void Game::chooseLevel() {
    int choice;
    cout << " ------------------------------------------------------------ " << endl;
    cout << "                  WELCOME TO FOLDING BLOCKS!                  " << endl;
    cout << " ------------------------------------------------------------ " << endl;
    cout << " ______________________________________ " << endl;
    cout << "|- Choose one of the available levels -|" << endl;
    cout << "| Level 1 (Warm Up)                    |" << endl;
    cout << "| Level 2 (Beginner)                   |" << endl;
    cout << "| Level 3 (Beginner)                   |" << endl;
    cout << "|______________________________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    switch(choice){
        case 1:
            level1();
            break;
        case 2:
            level2();
            break;
        case 3:
            level3();
            break;
    }
    board.defineBlocks();
    board.printBoard();
}

void Game::loopGame() {
    string colorInput;
    int n = colorInput.length();

    // declaring character array
    char char_array[n + 1];

    int row, col, move;
    while(!endGame()){

        //Gets block by color
        cout << "Choose the color of your block: "; cin.ignore(1000, '\n');
        getline(cin,colorInput);
        strcpy(char_array, colorInput.c_str());
        char color = char_array[0];

        pair<char, vector<pair<int,int>>> block = board.getBlock(color);
        row = block.second[0].first;
        col = block.second[0].second;

        cout << "Choose one move\n";
        cout << "1 - Reflexion right\n";
        cout << "2 - Reflexion left\n";
        cout << "3 - Reflexion down\n";
        cout << "4 - Reflexion up\n";
        cout << "Move: "; cin>>move;


        switch(move){
            case 1:
                board.reflexionBlockRight(row,col);
                board.defineBlocks();
                break;
            case 2:
                board.reflexionBlockLeft(row, col);
                board.defineBlocks();
                break;
            case 3:
                board.reflexionBlockDown(row,col);
                board.defineBlocks();
                break;
            case 4:
                board.reflexionBlockUp(row,col);
                board.defineBlocks();
                break;
        }
        board.printBoard();
    }
    cout << "End of game!\n";
}

