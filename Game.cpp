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

void Game::chooseLevel() {
    int choice;
    cout << "\n----WELCOME TO FOLDING BLOCKS!----\n\n";
    cout << "Choose what level you want to play: \n";
    cout << "--------------\n";
    cout << "----LEVELS----\n";
    cout << " - Level 1 - \n";
    cout << " - Level 2 - \n";
    cout << "....\n";
    cout << "\nChoice: ";
    cin>>choice;

    switch (choice){
        case 1:
            level1();
            break;
        case 2:
            level2();
            break;
    }

    board.printBoard();

    //TODO -> apagar
    board.reflexionRight(3,0);
    board.reflexionRight(2,1);

    board.printBoard();
}

