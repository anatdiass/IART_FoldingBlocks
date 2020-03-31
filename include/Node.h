#pragma once
#include "Game.h"
#include <list>
#include <queue>
#include <stack>
class Node
{
public:
	int id;
	bool visited;
    //used color
	char color;
	//used to save the coords of the pieces after a reflection
	int move;
	//level in the tree
	int level;
	//previousGame at the moment
	Game prevGame;
	//Board that we are playing at the moment
	Game actualGame;
	//vector with the children id
	vector<int> childrenIDs;
	Node *father;

	Node() {}
};

