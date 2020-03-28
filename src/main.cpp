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

    //board.defineBlocks();
    //cout << "Colors: "<< board.getBlocksColors().size()<< endl;
    //cout << "Colors: "<< g.getBoard().getBlocksColors().size() << endl;
}
