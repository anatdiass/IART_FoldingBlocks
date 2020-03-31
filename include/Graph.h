#pragma once
#include "Game.h"
#include "Node.h"

#include <list>
#include <queue>
#include <stack>



class Graph
{
private:
	Node firstNode;
public:
	vector<Node> allNodes;
	Graph() {}
	Graph(Game game) { loadGraph(game); }

	void loadGraph(Game game);
	void loadChildren(Node *node);

	Node getFirstNode() { return firstNode; };
	vector<Node>getAllNodes() { return allNodes; };

};

