#ifndef UNTITLED_ALGORITHMS_H
#define UNTITLED_ALGORITHMS_H

#include "Game.h"
#include <list>
#include <queue>

//using namespace std::chrono;

struct node{
    //used to save the piece or the block of pieces that were selected
    vector<int> selected;
    //used to save the coords of the pieces after a reflection
    vector<int> reflected;
    //level in the tree
    int level;
    //value of the node, used to aStar and greedy
    float value;
    //heuristic value of the node, used only for aStar
    float heuristic;
    //Board that we are playing at the moment
    Game prevGame;
    //pointer to the father node
    struct node *father;
};

void bfs(Game game);



#endif //UNTITLED_ALGORITHMS_H
