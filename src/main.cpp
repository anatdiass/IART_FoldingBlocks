#include <iostream>

#include "Algorithms.h"
#include "Game.h"

using namespace std;

int main() {

    /*TESTES*/

    Game g=Game();
    
    //g.loopGame();

    Board board=Board(4,4);
    board.setPiece(3,0,'R');

    g.setBoard(board);

    bfs(g);

    //cout << g.getNextValidMoves().size() ;
}
