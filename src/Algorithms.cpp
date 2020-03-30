#include <list>
#include <iostream>
#include "../include/Algorithms.h"
#include "../include/Game.h"

using namespace std;

struct node *currentNode;
vector<struct node> allNodes;

queue<struct node *> bfsTree;
stack<struct node *> dfsTree;

void bfs(Game game){

    Board b = game.getBoard();
    b.defineBlocks();

    b.printBoard();


    do {
        for (int i = 0; i < b.getNumRows(); i++){
            for (int j = 0; j < b.getNumCols(); j++){
                char colorPiece = b.getPieceColor(i,j);
                if(colorPiece != ' ' && colorPiece!= '-'){
                    vector<int> possibleMoves = game.getBlockNextValidMoves(colorPiece);
                    if (!possibleMoves.empty()){
                        for (int move : possibleMoves){
                            pair<int,int> actualCell = make_pair(i,j);
                            auto *newNode = new node();
                            newNode->color = colorPiece;
                            newNode->selected = actualCell;
                            newNode->move = move;
                            newNode->prevGame = game;
                            if (currentNode == NULL){
                                newNode->father = NULL;
                                newNode->level = 1;
                            }
                            else{
                                newNode->father = currentNode;
                                newNode->level = currentNode->level + 1;
                            }
                            bfsTree.push(newNode);
                        }
                    }
                }
            }
        }
        do {
            currentNode = bfsTree.front();
            bfsTree.pop();
            game = currentNode->prevGame;

            switch(currentNode->move){
                case 1:
                    if(game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);                        
                    }
                    game.getBoard().printBoard();
                    break;
                case 2:
                    if(game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 2);
                    }
                    game.getBoard().printBoard();
                    break;
                case 3:
                    if(game.verifyPlay(currentNode->color,3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color,3);
                    }
                    game.getBoard().printBoard();

                    break;
                case 4:
                    if(game.verifyPlay(currentNode->color,4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color,4);
                    }
                    game.getBoard().printBoard();
                    break;
                default:
                    break;
            }

            allNodes.push_back(*currentNode);
            if (game.checkVictory()){
                cout << "\n\nAI won at level: " << currentNode->level << "\n";
                return;
            }
        } while (!bfsTree.empty());

    } while (!game.endGame());
}

void dfs(Game game){
    Board b = game.getBoard();
    b.defineBlocks();

    b.printBoard();

    do {
        for (int i = 0; i < b.getNumRows(); i++){
            for (int j = 0; j < b.getNumCols(); j++){
                char colorPiece = b.getPieceColor(i,j);
                if(colorPiece != ' ' && colorPiece!= '-'){
                    vector<int> possibleMoves = game.getBlockNextValidMoves(colorPiece);
                    if (!possibleMoves.empty()){
                        for (int move : possibleMoves){
                            pair<int,int> actualCell = make_pair(i,j);
                            auto *newNode = new node();
                            newNode->color = colorPiece;
                            newNode->selected = actualCell;
                            newNode->move = move;
                            newNode->prevGame = game;
                            if (currentNode == NULL){
                                newNode->father = NULL;
                                newNode->level = 1;
                            }
                            else{
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

            switch(currentNode->move){
                case 1:
                    if(game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);                        
                    }
                    game.getBoard().printBoard();
                    break;
                case 2:
                    if(game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 2);
                    }
                    game.getBoard().printBoard();
                    break;
                case 3:
                    if(game.verifyPlay(currentNode->color,3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color,3);
                    }
                    game.getBoard().printBoard();

                    break;
                case 4:
                    if(game.verifyPlay(currentNode->color,4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color,4);
                    }
                    game.getBoard().printBoard();
                    break;
                default:
                    break;
            }
            allNodes.push_back(*currentNode);
            if (game.checkVictory()){
                cout << "\n\nAI won at level: " << currentNode->level << "\n";
                return;
            }
        } while (!dfsTree.empty());
    } while (!game.endGame());
}
