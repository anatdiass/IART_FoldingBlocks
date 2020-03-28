//
// Created by Maria Caldeira on 25/03/2020.
//

#include <list>
#include "Algorithms.h"

using namespace std;

void bfs(Game game)
{
    queue<struct node *> bfsTree;

    Board b = game.getBoard();
    b.defineBlocks();

    vector<char> allcolors = b.getBlocksColors();

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
    vector<int> validMoves = game.getBlockNextValidMoves(allcolors.at(0));
    b.printBoard();

    /*do
    {
        for (int i = 0; i < game.getBoard().getNumRows(); i++){
            for (int j = 0; j < game.getBoard().getNumCols(); j++)
            {
                /*vector<vector<int>> possibleMoves = game.possibleMovesList(i, j);
                if (possibleMoves.size() > 0)
                {
                    
                    for (unsigned int w = 0; w < possibleMoves.size(); w++)
                    {
                        vector<int> from = {i, j};
                        vector<int> to = possibleMoves.at(w);
                        struct node *newNode = new node();
                        newNode->from = from;
                        newNode->to = to;
                        newNode->prevGame = game;
                        if (currNode == NULL)
                        {
                            newNode->father = NULL;
                            newNode->level = 1;
                        }
                        else
                        {
                            newNode->father = currNode;
                            newNode->level = currNode->level + 1;
                        }
                        bfsTree.push(newNode);
                    }
                }
            }
        }
        do
        {
            currNode = bfsTree.front();
            bfsTree.pop();
            game = currNode->prevGame;
            game.swapPiecesAI(currNode->from[0], currNode->from[1], currNode->to[0], currNode->to[1]);
            while (game.applyGravity() || game.verifyCombos())
                ;
            if (checkDuplicated(game.getBoard().getBoard(), currNode->level))
                continue;
            else
                allNodes.push_back(*currNode);
            if (game.checkVictory())
            {
                getSolution();
                cout << "\n\n\n\nVitoria do bot em : " << currNode->level << "\n";
                stopClock();
                return;
            }
        } while (!game.endGame() );

    } while (bfsTree.size() > 0);
    cout << "\n\nError, not a valid board because not a valid sequence found!\n\n";*/
}
