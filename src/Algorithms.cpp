#include <list>
#include <iostream>
#include "../include/Algorithms.h"
#include "../include/Game.h"

using namespace std;

struct node *currentNode;
vector<struct node> allNodes;

queue<struct node *> bfsTree;

void bfs(Game game)
{

    Board b = game.getBoard();
    b.defineBlocks();
    game.calculateValidMoves();

    b.printBoard();

    cout << "Possible moves: " << game.nrValidMoves() << endl;
    game.printValidMoves();

    /****************************************NOTA*********************************************/
    //Sempre que se faz uma reflexao fazer b.defineBlocks + game.setBoard(b)

    do{
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
                            if (currentNode == NULL)
                            {
                                newNode->father = NULL;
                                newNode->level = 1;
                            }
                            else
                            {
                                newNode->father = currentNode;
                                newNode->level = currentNode->level + 1;
                            }
                            bfsTree.push(newNode);
                        }
                    }
                }
            }
        }

        do
        {
            currentNode = bfsTree.front();
            bfsTree.pop();
            game = currentNode->prevGame;



            switch(currentNode->move){
                case 1:
                    if(b.verifyReflexionBlockRight(currentNode->color)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        b.reflexionBlockRight(currentNode->color);
                        b.defineBlocks();
                        game.setBoard(b);
                        b.printBoard();
                        game.calculateValidMoves();
                        cout << "Possible moves: " << game.nrValidMoves() << endl;
                        game.printValidMoves();
                    }
                    break;
                case 2:
                    if(b.verifyReflexionBlockLeft(currentNode->color)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;
                        b.reflexionBlockLeft(currentNode->color);
                        b.defineBlocks();
                        game.setBoard(b);
                        b.printBoard();
                        game.calculateValidMoves();
                        cout << "Possible moves: " << game.nrValidMoves() << endl;
                        game.printValidMoves();
                    }
                    break;
                case 3:
                    if(b.verifyReflexionBlockDown(currentNode->color)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        b.reflexionBlockDown(currentNode->color);
                        b.defineBlocks();
                        game.setBoard(b);
                        b.printBoard();
                        game.calculateValidMoves();
                        cout << "Possible moves: " << game.nrValidMoves() << endl;
                        game.printValidMoves();
                    }
                    break;
                case 4:
                    if(b.verifyReflexionBlockUp(currentNode->color)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        b.reflexionBlockUp(currentNode->color);
                        b.defineBlocks();
                        game.setBoard(b);
                        b.printBoard();
                        game.calculateValidMoves();
                        cout << "Possible moves: " << game.nrValidMoves() << endl;
                        game.printValidMoves();
                    }
                    break;
                default:
                    break;
            }

            allNodes.push_back(*currentNode);
            if (game.checkVictory()){
                cout << "\n\n\n\nAI won at level: " << currentNode->level << "\n";
                return;
            }
        } while (!game.endGame() /*|| currentNode->level >= game.getMaxMoves())*/);

    } while (!bfsTree.empty());
    cout << "\n\nError, not a valid board because not a valid sequence found!\n\n";
}

