#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include <string>

#include "Board.h"


class Game {
private:
    Board board;
public:
    Game();

    /**
     * Defines the board of first level
     */
    void level1();

    /**
     * Defines the board of second level
     */
    void level2();

    /**
     * Defines the board of third level
     */
    void level3();

    /**
     * Allows the user to choose which level to play
     */
    void chooseLevel();

    /**
     * Verify if the board is full (all the pieces have a color)
     * @return True if the board is full
     */
    bool checkVictory();

    /**
     * Verify if the game is over (victory or loss)
     * @return True if the game is over
     */
    bool endGame();

    void loopGame();

    vector<vector<int>> possibleMoves(int row, int col);
};


#endif //UNTITLED_GAME_H
