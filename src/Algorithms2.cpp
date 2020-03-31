#include "Algorithms.h"
#include "Node.h"
#include "Graph.h"

stack<Node*> dfsTree2;
queue<Node*> bfsTree2;

Node * currNode;

void dfs_v2(Game game) {
	int nMoves = 0;
	Board b = game.getBoard();
	b.defineBlocks();

	Graph graph = Graph(game);
	dfsTree2.push(&graph.allNodes[0]);
	
	do{
		currNode = dfsTree2.top();

		for (int i = 0; i < (int)graph.allNodes.size(); i++) {

			if (graph.allNodes[i].id == currNode->id) {
				graph.allNodes[i].visited == true;
				break;
			}
		}
		//currNode->visited = true;
		dfsTree2.pop();
		currNode->actualGame.getBoard().printBoard();
		
		if (currNode->actualGame.checkVictory()) {
			cout << "\n\nAI won at level: " << currNode->level << endl<<"Nmoves: " << nMoves;
			return;
		}
		

		for (auto & child : currNode->childrenIDs) {

			for (int i = 0; i < (int)graph.allNodes.size(); i++) {

				if (graph.allNodes[i].id == child) {
					dfsTree2.push(&graph.allNodes[i]);
					break;
				}
			}

		}
		nMoves++;

	} while (!dfsTree2.empty());
}

void bfs_v2(Game game) {
	int nMoves = 0;
	Board b = game.getBoard();
	b.defineBlocks();

	Graph graph = Graph(game);
	bfsTree2.push(&graph.allNodes[0]);
	
	do{
		currNode = bfsTree2.front();

		for (int i = 0; i < (int)graph.allNodes.size(); i++) {

			if (graph.allNodes[i].id == currNode->id) {
				graph.allNodes[i].visited == true;
				break;
			}
		}
		//currNode->visited = true;
		bfsTree2.pop();
		currNode->actualGame.getBoard().printBoard();
		
		if (currNode->actualGame.checkVictory()) {
			cout << "\n\nAI won at level: " << currNode->level << endl<<"Nmoves: " << nMoves;
			return;
		}
		

		for (auto & child : currNode->childrenIDs) {

			for (int i = 0; i < (int)graph.allNodes.size(); i++) {

				if (graph.allNodes[i].id == child) {
					bfsTree2.push(&graph.allNodes[i]);
					break;
				}
			}

		}
		nMoves++;

	} while (!bfsTree2.empty());
}


