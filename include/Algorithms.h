#ifndef UNTITLED_ALGORITHMS_H
#define UNTITLED_ALGORITHMS_H

#include "Game.h"
#include <list>
#include <queue>
#include <stack>

struct node {
    //store the color of the block that was selected
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
    float heuristicValue;

    //Board that we are playing at the moment
    Game prevGame;

    //Board that we are playing at the moment
    Game actualGame;

    //pointer to the father node
    struct node *father;
};

/**
 * Gets and print a solution using bfs
 * @param game Game
 */
void bfs(Game game);

void bfs_v2(Game game);

/**
 * Gets and print a solution using dfs
 * @param game Game
 */
void dfs(Game game);

void dfs_v2(Game game);

/**
 * Gets and print a solution using greedy
 * @param game Game
 */
void greedy(Game game);

/**
 * Gets and print a solution using aStar depending on what function was chosen
 * @param game Game
 * @param heuristicFunction Heuristic function
 */
void aStar(Game game, int heuristicFunction);

/**
 * Gets the greedy value of a move
 * @param game Game
 * @param move Move
 * @param blockColor Color of block
 * @return Greedy value
 */
int getGreedyValue(Game game, int move, char blockColor);

/**
 * Gets the number of colorful pieces of board
 * @param b Board
 * @return Number of colorful pieces
 */
int getTotalPiecesBoard(Board b);

/**
 * Returns the index of node with highest value
 * @param nodes Vector of nodes
 * @return Index of highest node
 */
int getBestValue(vector<struct node *> &nodes);

/**
 * Verify if a vector of nodes contains a node with specified value
 * @param v Vector of nodes
 * @param value Value to verify
 * @return True if the vector contains the node
 */
bool valueExist(vector<struct node*> v, float value);

/**
 * Stores all the nodes in the aStarTree of vector v by value
 * @param v Vector with nodes
 */
void orderAStarTree(vector<struct node *> &v);

/**
 * Returns the index of node with lowest value
 * @param nodes Vector of nodes
 * @return Index of lowest node
 */
int getMinVal(vector<struct node *> &nodes);

/**
 * Calculates the heuristic value depending on what function was chosen
 * @param game Game
 * @param move Move
 * @param blockColor Color of block
 * @param heuristic Heuristic function
 * @return Heuristic value
 */
float getHeuristicValue(Game game, int move, char blockColor, int heuristic);

/**
 * Verify if a vector of nodes contains a node with specified heuristic value
 * @param v Vector of nodes
 * @param value Value to verify
 * @return True if the vector contains the node
 */
bool heuristicValueExist(vector<struct node*>v, float value);


#endif //UNTITLED_ALGORITHMS_H


