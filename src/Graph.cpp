#include "Graph.h"

int id;
void Graph::loadGraph(Game game) {
	id = 0;
	firstNode.id = 0;
	firstNode.level = 0;
	firstNode.actualGame = game;
	firstNode.visited = false;

	allNodes.push_back(firstNode);
	loadChildren(&firstNode);

}

void Graph::loadChildren(Node *node) {

	vector<pair<char, vector<int>>> allMoves = node->actualGame.getNextValidMoves();

	if (!allMoves.empty()) {

		for (auto & block : allMoves) {

			for (int currMove : block.second) {
				id++;
				Node newNode = Node();
				newNode.id = id;
				newNode.prevGame = node->actualGame;
				newNode.level = node->level + 1;
				newNode.visited = false;

				newNode.color = block.first;
				newNode.move = currMove;
				newNode.actualGame = newNode.prevGame;

				if (newNode.actualGame.verifyPlay(newNode.color, newNode.move)) {
					newNode.actualGame.play(newNode.color, newNode.move);
				}
				else newNode.actualGame.getBoard().printBoard();

				allNodes.push_back(newNode);

				for (Node & n : allNodes) {
					if (n.id == node->id) {
						n.childrenIDs.push_back(newNode.id);
					}
				}

				loadChildren(&newNode);
			}

		}

	}
	
}
	
	