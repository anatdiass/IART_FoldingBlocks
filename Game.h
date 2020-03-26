#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "Board.h"

class Game {
private:
    Board board;
public:
    Game();

    void chooseLevel();
    void level1();
    void level2();
    void level3();
    bool checkVictory();
    bool endGame();
};


#endif //UNTITLED_GAME_H
