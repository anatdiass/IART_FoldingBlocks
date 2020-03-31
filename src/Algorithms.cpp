#include <list>
#include <iostream>
#include "Algorithms.h"
#include "Game.h"

using namespace std;

struct node *currentNode;
struct node *node_var;
vector<struct node> allNodes;

queue<struct node *> bfsTree;
queue<struct node *> bfsTree_parents;
stack<struct node *> dfsTree;

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
                        if (bfsTree_parents.size() > 0) {
                            bfsTree_parents.pop();
                        }
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

    } while (!game.checkVictory() || !game.endGame());
}

void dfs(Game game) {
    int nMoves = 0;
    Board b = game.getBoard();
    b.defineBlocks();

    b.printBoard();

    do {
        for (int i = 0; i < b.getNumRows(); i++) {
            for (int j = 0; j < b.getNumCols(); j++) {
                char colorPiece = b.getPieceColor(i, j);
                if (colorPiece != ' ' && colorPiece != '-') {
                    vector<int> possibleMoves = game.getBlockNextValidMoves(colorPiece);
                    if (!possibleMoves.empty()) {
                        for (int move : possibleMoves) {
                            pair<int, int> actualCell = make_pair(i, j);
                            auto *newNode = new node();
                            newNode->color = colorPiece;
                            newNode->selected = actualCell;
                            newNode->move = move;
                            newNode->prevGame = game;
                            if (currentNode == NULL) {
                                newNode->father = NULL;
                                newNode->level = 1;
                            }
                            else {
                                newNode->father = currentNode;
                                newNode->level = currentNode->level + 1;
                            }
                            dfsTree.push(newNode);
                        }
                    }
                }
            }
        }
        do {
            currentNode = dfsTree.top();
            dfsTree.pop();
            game = currentNode->prevGame;

            switch (currentNode->move) {
                case 1:
                    if (game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                case 2:
                    if (game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 2);
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                case 3:
                    if (game.verifyPlay(currentNode->color, 3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 3);
                        nMoves++;
                    }
                    game.getBoard().printBoard();

                    break;
                case 4:
                    if (game.verifyPlay(currentNode->color, 4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 4);
                        nMoves++;
                    }
                    game.getBoard().printBoard();
                    break;
                default:
                    break;
            }
            allNodes.push_back(*currentNode);
            if (game.checkVictory()) {
                cout << "\n\nAI won at level: " << currentNode->level << "\n";
                cout << "Total moves: " << nMoves << endl;
                return;
            }
        } while (!dfsTree.empty());
    } while (!game.endGame());
}
