#ifndef UNTITLED_ALGORITHMS_H
#define UNTITLED_ALGORITHMS_H

#include "Game.h"
#include <list>
#include <queue>
#include <stack>

//using namespace std::chrono;

struct node {
    char color;
    //used to save the piece or the block of pieces that were selected
    pair<int, int> selected;
    //used to save the coords of the pieces after a reflection
    int move;
    //level in the tree
    int level;
    //value of the node, used to aStar and greedy
    float value;
    //heuristic value of the node, used only for aStar
    float heuristic;
    //Board that we are playing at the moment
    Game prevGame;
    //
    //Board that we are playing at the moment
    Game actualGame;
    //pointer to the father node
    struct node *father;
};


void selectAlgorithm(Game game);
void bfs(Game game);
void dfs(Game game);
void greedy(Game game);
int calculateGreedyValue(Game game, int move, char blockColor);
int getTotalPieces(Board b);
int getBestValue(vector<struct node *> &avl);


#endif //UNTITLED_ALGORITHMS_H


