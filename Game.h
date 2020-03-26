#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "Board.h"

class Game {
private:
public:
    Game();

    //TODO -> board tem de ser private --> public so para testar no main
    Board board;

    bool checkFullBoard();
};


#endif //UNTITLED_GAME_H
