#include <iostream>

#include "Algorithms.h"
#include "Game.h"

using namespace std;

void selectMode(Game game){
    int choice;
    cout << " ____________________ " << endl;
    cout << "|- Choose game mode -|" << endl;
    cout << "| 1 - Player         |" << endl;
    cout << "| 2- AI              |" << endl;
    cout << "|____________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    switch(choice){
        case 1:
            game.chooseLevel();
            game.loopGame();
            break;
        case 2:
            game.chooseLevel();
            bfs(game);
            break;
    }
}

int main() {
    cout << " ------------------------------------------------------------ " << endl;
    cout << "                  WELCOME TO FOLDING BLOCKS!                  " << endl;
    cout << " ------------------------------------------------------------ " << endl;

    Game game;
    selectMode(game);
    return 0;

    /*TESTES*/
/*
    Board board=Board(4,4);
    board.setPiece(3,0,'R');

    g.setBoard(board);

    bfs(g);*/

    //cout << g.getNextValidMoves().size() ;
}
