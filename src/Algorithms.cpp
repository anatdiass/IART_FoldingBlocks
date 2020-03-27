//
// Created by Maria Caldeira on 25/03/2020.
//

#include <list>
#include "Algorithms.h"

using namespace std;

void bfs(Game game)
{
    // Mark all the vertices as not visited
    //int N = board.getNumCols() * board.getNumRows();

    queue<struct node *> bfsTree;

    do
    {
        for (int i = 0; i < (int)game.getBoard().getBoard().size(); i++){
            for (int j = 0; j < (int)game.getBoard().getBoard().at(i).size(); j++)
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
                return;*/
            }
        } while (!game.endGame() );

    } while (bfsTree.size() > 0);
    cout << "\n\nError, not a valid board because not a valid sequence found!\n\n";
}
