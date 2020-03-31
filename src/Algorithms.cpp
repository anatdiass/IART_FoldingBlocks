#include <list>
#include <iostream>
#include <climits>
#include "Algorithms.h"
#include "Game.h"

using namespace std;

struct node *currentNode;
struct node *node_var;

vector<struct node> allNodes;

queue<struct node *> bfsTree;
queue<struct node *> bfsTree_parents;
stack<struct node *> dfsTree;
stack<struct node *> greedyTree;
stack<struct node *> greedyTree_parents;

void bfs(Game game) {

    int nMoves = 0;
    Board b = game.getBoard();
    b.defineBlocks();

    b.printBoard();


    do {
        for (int i = 0; i < b.getNumRows(); i++) {
            for (int j = 0; j < b.getNumCols(); j++) {
                char colorPiece = b.getPieceColor(i, j);
                if (colorPiece != ' ' && colorPiece != '-') {
                    vector<int> possibleMoves;
                    if (currentNode == NULL) {

                        possibleMoves = game.getBlockNextValidMoves(colorPiece);
                    }
                    else {
                        if(!bfsTree_parents.empty())
                            node_var = bfsTree_parents.front();
                        possibleMoves = node_var->actualGame.getBlockNextValidMoves(colorPiece);
                    }

                    if (!possibleMoves.empty()) {
                        for (int move : possibleMoves) {
                            pair<int, int> actualCell = make_pair(i, j);
                            auto *newNode = new node();
                            newNode->color = colorPiece;
                            newNode->selected = actualCell;
                            newNode->move = move;

                            if (currentNode == NULL) {
                                newNode->father = NULL;
                                newNode->level = 1;
                                newNode->prevGame = game;
                            }
                            else {

                                newNode->father = node_var;
                                newNode->prevGame = newNode->father->actualGame;
                                newNode->level = newNode->father->level + 1;

                            }
                            bfsTree.push(newNode);
                        }
                    }
                    if (bfsTree_parents.size() > 0) {
                        bfsTree_parents.pop();
                    }
                }
            }
        }
        do {
            currentNode = bfsTree.front();
            bfsTree.pop();
            bfsTree_parents.push(currentNode);

/*
            if (bfsTree_parents.empty()) {
                bfsTree_parents.push(currentNode);
            }
            else {
                struct node *bfsTree_parents_var = bfsTree_parents.front();

                if (bfsTree_parents_var == currentNode) {
                    bfsTree_parents.push(currentNode);
                }
            }
*/

            game = currentNode->prevGame;

            game.printValidMoves();

            switch (currentNode->move) {
                case 1:
                    if (game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();

                    break;
                case 2:
                    if (game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;

                        game.play(currentNode->color, 2);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                case 3:
                    if (game.verifyPlay(currentNode->color, 3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 3);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();

                    break;
                case 4:
                    if (game.verifyPlay(currentNode->color, 4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 4);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                default:
                    break;
            }

            game.setBoard(b);
            currentNode->actualGame = game;
            allNodes.push_back(*currentNode);
            if (game.checkVictory()) {
                cout << "\n\nAI won at level: " << currentNode->level << "\n";
                cout << "Total moves: " << nMoves << endl;
                return;
            }
        } while (!bfsTree.empty());

    } while (!game.checkVictory() || !game.getNextValidMoves().empty());
}

void dfs(Game game) {
	int nMoves = 0;
	Board b = game.getBoard();
	b.defineBlocks();

	b.printBoard();

	bool move_possible;

	do {
		for (int i = 0; i < b.getNumRows(); i++) {
			for (int j = 0; j < b.getNumCols(); j++) {
				char colorPiece = b.getPieceColor(i, j);
				if (colorPiece != ' ' && colorPiece != '-') {

					do {
						int level = 0;
						vector<int> possibleMoves;
						move_possible = true;
						if (currentNode == NULL) {

							possibleMoves = game.getBlockNextValidMoves(colorPiece);
						}
						else {
							possibleMoves = currentNode->actualGame.getBlockNextValidMoves(colorPiece);

							if (possibleMoves.empty()) {
								/*node_var = currentNode;
								//currentNode = node_var->father;
								possibleMoves = currentNode->prevGame.getBlockNextValidMoves(colorPiece);
								//vector<int>::iterator it;

								for (int move = 1; move < possibleMoves.size()+1; move++) {
									if (node_var->move == move) {
										possibleMoves.erase(possibleMoves.begin(), possibleMoves.begin() + i-1);
										move--;
									}
								}*/
								move_possible = false;
								if (!dfsTree_parents.empty())
									dfsTree_parents.pop();
							}
						}

						if (move_possible) {

							if (!possibleMoves.empty()) {
								for (int move : possibleMoves) {
									pair<int, int> actualCell = make_pair(i, j);
									auto *newNode = new node();
									newNode->color = colorPiece;
									newNode->selected = actualCell;
									newNode->move = move;

									if (currentNode == NULL) {
										newNode->father = NULL;
										newNode->level = 1;
										newNode->prevGame = game;

										if (level == 0) {
											dfsTree.push(newNode);
										}
										level++;
									}
									else {

										newNode->father = node_var;
										newNode->prevGame = currentNode->actualGame;
										newNode->level = currentNode->level + 1;
										if (level == 0) {
											dfsTree.push(newNode);
										}
										level++;
									}

								}
							}

							currentNode = dfsTree.top();
							dfsTree.pop();
							dfsTree_parents.push(currentNode);
							game = currentNode->prevGame;

							switch (currentNode->move) {
							case 1:
								if (game.verifyPlay(currentNode->color, 1)) {
									cout << "\n\nTree level: " << currentNode->level;
									cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
									game.play(currentNode->color, 1);
									//b = game.getBoard();
									nMoves++;
								}
								game.getBoard().printBoard();
								break;
							case 2:
								if (game.verifyPlay(currentNode->color, 2)) {
									cout << "\n\nTree level: " << currentNode->level;
									cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;
									game.play(currentNode->color, 2);
									//b = game.getBoard();
									nMoves++;
								}
								game.getBoard().printBoard();
								break;
							case 3:
								if (game.verifyPlay(currentNode->color, 3)) {
									cout << "\n\nTree level: " << currentNode->level;
									cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
									game.play(currentNode->color, 3);
									//b = game.getBoard();
									nMoves++;
								}
								game.getBoard().printBoard();

								break;
							case 4:
								if (game.verifyPlay(currentNode->color, 4)) {
									cout << "\n\nTree level: " << currentNode->level;
									cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
									game.play(currentNode->color, 4);
									//b = game.getBoard();
									nMoves++;
								}
								game.getBoard().printBoard();
								break;
							default:
								break;
							}

							//game.setBoard(b);
							currentNode->actualGame = game;
							allNodes.push_back(*currentNode);
							if (game.checkVictory()) {
								cout << "\n\nAI won at level: " << currentNode->level << "\n";
								cout << "Total moves: " << nMoves << endl;
								return;
							}
						}
					} while (!dfsTree.empty());
				}
			}
		}

	} while (!game.endGame() || !game.getNextValidMoves().empty());
}




void greedy(Game game){
    vector<struct node *> children;

    int nMoves = 0;
    Board b = game.getBoard();
    b.defineBlocks();

    b.printBoard();

    do {
        for (int i = 0; i < b.getNumRows(); i++) {
            for (int j = 0; j < b.getNumCols(); j++) {
                char colorPiece = b.getPieceColor(i, j);
                if (colorPiece != ' ' && colorPiece != '-') {
                    vector<int> possibleMoves;
                    if (currentNode == NULL) {

                        possibleMoves = game.getBlockNextValidMoves(colorPiece);
                    }
                    else {
                        if(!greedyTree_parents.empty())
                            node_var = greedyTree_parents.top();
                        possibleMoves = node_var->actualGame.getBlockNextValidMoves(colorPiece);
                    }

                    if (!possibleMoves.empty()) {
                        for (int move : possibleMoves) {
                            pair<int, int> actualCell = make_pair(i, j);
                            auto *newNode = new node();
                            newNode->color = colorPiece;
                            newNode->selected = actualCell;
                            newNode->move = move;
                            newNode->value = calculateGreedyValue(game,move,colorPiece);
                            if (newNode->value != -1) {
                                if (currentNode == NULL) {
                                    newNode->father = NULL;
                                    newNode->level = 1;
                                    newNode->prevGame = game;
                                } else {

                                    newNode->father = node_var;
                                    newNode->prevGame = newNode->father->actualGame;
                                    newNode->level = newNode->father->level + 1;

                                }
                                greedyTree.push(newNode);
                                children.push_back(newNode);
                            }
                        }
                    }
                    if (greedyTree_parents.size() > 0) {
                        greedyTree_parents.pop();
                    }
                }
            }
        }
        while (children.size() > 0){
            int index = getBestValue(children);
            greedyTree.push(children.at(index));
            children.erase(children.begin() + index);
        }

        do {
            currentNode = greedyTree.top();
            greedyTree.pop();
            greedyTree_parents.push(currentNode);

            game = currentNode->prevGame;

            game.printValidMoves();

            switch (currentNode->move) {
                case 1:
                    if (game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();

                    break;
                case 2:
                    if (game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;

                        game.play(currentNode->color, 2);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                case 3:
                    if (game.verifyPlay(currentNode->color, 3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 3);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();

                    break;
                case 4:
                    if (game.verifyPlay(currentNode->color, 4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 4);
                        b = game.getBoard();
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                default:
                    break;
            }

            game.setBoard(b);
            currentNode->actualGame = game;
            allNodes.push_back(*currentNode);
            if (game.checkVictory()) {
                cout << "\n\nAI won at level: " << currentNode->level << "\n";
                cout << "Total moves: " << nMoves << endl;
                return;
            }
        } while (greedyTree.size() > 0);
     } while (!game.endGame() || !game.checkVictory());
}

int getBestValue(vector<struct node *> &avl)
{
    int maxValue = INT_MIN;
    int i = 0;
    for (int k = 0; k < (int)avl.size(); k++)
    {
        int curValue = avl.at(k)->value;
        if (maxValue < curValue)
        {
            maxValue = curValue;
            i = k;
        }
    }
    return i;
}

int calculateGreedyValue(Game game, int move, char blockColor)
{
    if(game.verifyPlay(blockColor, move)){
        game.play(blockColor,move);
    }
    while (game.getNextValidMoves().size()>0)
        ;
    if (game.endGame())
        return -1;
    else
        return getTotalPieces(game.getBoard());
}

int getTotalPieces(Board b){
    int sum=0;
    for(int i=0;i<b.getNumRows();i++){
        for(int j=0;j<b.getNumCols();j++){
            if(b.getPieceColor(i,j)!=' ' && b.getPieceColor(i,j)!='-')
                sum++;
        }
    }
    return sum;
}
