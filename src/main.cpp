#include <iostream>

#include "Algorithms.h"
#include "Game.h"

using namespace std;

int main() {

    /*TESTES*/

    Game g=Game();
    
    //g.loopGame();

    Board board=Board(8,4);

    //Yellow pieces
    board.setPiece(0,0,'A');
    board.setPiece(0,1,'A');
    board.setPiece(1,0,'A');
    board.setPiece(1,1,'A');
    board.setPiece(2,3,'A');

    //Blue piece
    board.setPiece(2,2,'B');

    //Red piece
    board.setPiece(6,3,'V');

    g.setBoard(board);

    bfs(g);

    //board.defineBlocks();
    //cout << "Colors: "<< board.getBlocksColors().size()<< endl;
    //cout << "Colors: "<< g.getBoard().getBlocksColors().size() << endl;
}
