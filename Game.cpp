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

void Game::level1() {                                               /*   ._____._____._____._____.   */
    this->board=Board(4,4);                           /*   |     |     |     |     |   */
    this->board.setPiece(3,0,'R');                  /*   ._____._____._____._____.   */
    this->board=Board(4,4);                           /*   |     |     |     |     |   */
                                                                    /*   ._____._____._____._____.   */
                                                                    /*   |     |     |     |     |   */
                                                                    /*   ._____._____._____._____.   */
                                                                    /*   |  R  |     |     |     |   */
                                                                    /*   ._____._____._____._____.   */
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

