#include <list>
#include <iostream>
#include "../include/Algorithms.h"
#include "../include/Game.h"

using namespace std;

struct node *currentNode;
vector<struct node> allNodes;

void bfs(Game game)
{
    queue<struct node *> bfsTree;

    Board b = game.getBoard();
    b.defineBlocks();

    /****************************************NOTA*********************************************/
    //Sempre que se faz uma reflexao fazer b.defineBlocks + game.setBoard(b)


    /*for (int i = 0; i < b.getNumRows(); i++){
        for (int j = 0; j < b.getNumCols(); j++){
            for(int k = 0; k < (int)allcolors.size(); k++){

                vector<int> validMoves = game.getBlockNextValidMoves(allcolors.at(k));
                //cout << validMoves.size()<<endl;
                if (validMoves.size() > 0)
                {
                    for (int z = 0; z < (int)validMoves.size(); z++)
                    {
                        cout << "++" << endl;
                        int reflection = validMoves.at(z);

                        switch(reflection){
                            case 1:
                            b.setPiece(i,j+1,allcolors.at(k));
                            cout << "right" << endl;
                            break;
                            case 2:
                            b.setPiece(i,j-1,allcolors.at(k));
                            break;
                            case 3:
                            b.setPiece(i-1,j,allcolors.at(k));
                            break;
                            case 4:
                            b.setPiece(i+1,j,allcolors.at(k));
                            break;
                            default:
                            break;
                        }

                    }
                }
            }
        }
    }*/
    //vector<int> validMoves = game.getBlockNextValidMoves(allcolors.at(0));
//    b.printBoard();

    do{
        for (int i = 0; i < b.getNumRows(); i++){
            for (int j = 0; j < b.getNumCols(); j++){
                char colorPiece = b.getPieceColor(i,j);
                if(colorPiece != ' ' && colorPiece!= '-'){
                    vector<int> possibleMoves = game.getBlockNextValidMoves(colorPiece);
                    if (!possibleMoves.empty()){
                        for (int move : possibleMoves){
                            pair<int,int> actualCell = make_pair(i,j);
                            struct node *newNode = new node();
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
                    b.reflexionBlockRight(currentNode->color);
                    b.defineBlocks();
                    game.setBoard(b);
                    b.printBoard();
                    break;
                case 2:
                    b.reflexionBlockLeft(currentNode->color);
                    b.defineBlocks();
                    game.setBoard(b);
                    b.printBoard();
                    break;
                case 3:
                    b.reflexionBlockDown(currentNode->color);
                    b.defineBlocks();
                    game.setBoard(b);
                    b.printBoard();
                    break;
                case 4:
                    b.reflexionBlockUp(currentNode->color);
                    b.defineBlocks();
                    game.setBoard(b);
                    b.printBoard();
                    break;
                default:
                    break;
            }

            /*   if (checkDuplicated(game.getBoard().getBoard(), currNode->level))
                   continue;
               else*/
            allNodes.push_back(*currentNode);
            if (game.checkVictory())
            {
                b.printBoard();
                //getSolution();
                cout << "\n\n\n\nVitoria do bot em : " << currentNode->level << "\n";
                //stopClock();
                return;
            }
        } while (!game.endGame() /*|| currentNode->level >= game.getMaxMoves())*/);

    } while (!bfsTree.empty());
    cout << "\n\nError, not a valid board because not a valid sequence found!\n\n";




}

