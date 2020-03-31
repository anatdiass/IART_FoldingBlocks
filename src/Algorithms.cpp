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
stack<struct node *> dfsTree_parents;
stack<struct node *> greedyTree;
stack<struct node *> greedyTree_parents;
queue<struct node *> aStarTree;
queue<struct node *> aStarTree_parents;

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

            game = currentNode->prevGame;

            switch (currentNode->move) {
                case 1:
                    if (game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 2:
                    if (game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;

                        game.play(currentNode->color, 2);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 3:
                    if (game.verifyPlay(currentNode->color, 3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 3);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 4:
                    if (game.verifyPlay(currentNode->color, 4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 4);
                        b = game.getBoard();
                        nMoves++;
                    }
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
                game.getBoard().printBoard();
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
                                    break;
                                case 2:
                                    if (game.verifyPlay(currentNode->color, 2)) {
                                        cout << "\n\nTree level: " << currentNode->level;
                                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;
                                        game.play(currentNode->color, 2);
                                        //b = game.getBoard();
                                        nMoves++;
                                    }
                                    break;
                                case 3:
                                    if (game.verifyPlay(currentNode->color, 3)) {
                                        cout << "\n\nTree level: " << currentNode->level;
                                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                                        game.play(currentNode->color, 3);
                                        //b = game.getBoard();
                                        nMoves++;
                                    }
                                    break;
                                case 4:
                                    if (game.verifyPlay(currentNode->color, 4)) {
                                        cout << "\n\nTree level: " << currentNode->level;
                                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                                        game.play(currentNode->color, 4);
                                        //b = game.getBoard();
                                        nMoves++;
                                    }
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
                                game.getBoard().printBoard();
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
                            newNode->value = getGreedyValue(game,move,colorPiece);
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
                                if(!valueExist(children,newNode->value))
                                    children.push_back(newNode);
                            }
                            else{
                                if(currentNode!=NULL){
                                    newNode->father=node_var;
                                    newNode->prevGame=newNode->father->actualGame;
                                    newNode->level=newNode->father->level+1;
                                }
                                greedyTree.push(newNode);
                            }
                        }
                    }
                    if (!greedyTree_parents.empty()) {
                        greedyTree_parents.pop();
                    }
                }
            }
        }
        while (!children.empty()){
            int id = getBestValue(children);
            greedyTree.push(children.at(id));
            children.erase(children.begin() + id);
        }

        do {
            currentNode = greedyTree.top();
            greedyTree.pop();
            greedyTree_parents.push(currentNode);

            game = currentNode->prevGame;

            switch (currentNode->move) {
                case 1:
                    if (game.verifyPlay(currentNode->color, 1)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMOVE: right reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 1);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 2:
                    if (game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;

                        game.play(currentNode->color, 2);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 3:
                    if (game.verifyPlay(currentNode->color, 3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 3);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 4:
                    if (game.verifyPlay(currentNode->color, 4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 4);
                        b = game.getBoard();
                        nMoves++;
                    }
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
                game.getBoard().printBoard();
                return;
            }
        } while (!greedyTree.empty());
    } while (!game.endGame() || !game.checkVictory());
}

int getGreedyValue(Game game, int move, char blockColor){
    Game g2 = game;
    if(g2.verifyPlay(blockColor,move))
        g2.play(blockColor,move);

    if (g2.checkVictory() || g2.getNextValidMoves().empty())
        return -1;
    else
        return getTotalPiecesBoard(g2.getBoard());
}

int getTotalPiecesBoard(Board b){
    int sum=0;
    for(int i=0;i<b.getNumRows();i++){
        for(int j=0;j<b.getNumCols();j++){
            if(b.getPieceColor(i,j)!=' ' && b.getPieceColor(i,j)!='-')
                sum++;
        }
    }
    return sum;
}

int getBestValue(vector<struct node *> &nodes){
    int max = -2;
    int i = 0;
    for (int j=0; j<(int)nodes.size(); j++){
        int val = nodes.at(j)->value;
        if (val>max){
            max=val;
            i=j;
        }
    }
    return i;
}

bool valueExist(vector<struct node*> v, float value){
    for(auto node: v){
        if (node->value==value)
            return true;
    }
    return false;
}

void aStar(Game game, int heuristic){
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
                        if(!aStarTree_parents.empty())
                            node_var = aStarTree_parents.front();
                        possibleMoves = node_var->actualGame.getBlockNextValidMoves(colorPiece);
                    }

                    if (!possibleMoves.empty()) {
                        for (int move : possibleMoves) {
                            pair<int, int> actualCell = make_pair(i, j);
                            auto *newNode = new node();
                            newNode->color = colorPiece;
                            newNode->selected = actualCell;
                            newNode->move = move;
                            newNode->heuristicValue = getHeuristicValue(game, move,colorPiece, heuristic);
                            if (newNode->heuristicValue != -1) {
                                if (currentNode == NULL) {
                                    newNode->father = NULL;
                                    newNode->level = 1;
                                    newNode->prevGame = game;
                                } else {

                                    newNode->father = node_var;
                                    newNode->prevGame = newNode->father->actualGame;
                                    newNode->level = newNode->father->level + 1;

                                }
                                if(!heuristicValueExist(children,newNode->heuristicValue))
                                    children.push_back(newNode);
                                newNode->value = newNode->heuristicValue + newNode->level;

                            }
                            else{
                                if(currentNode!=NULL){
                                    newNode->father=node_var;
                                    newNode->prevGame=newNode->father->actualGame;
                                    newNode->level=newNode->father->level+1;
                                }
                                newNode->value = newNode->heuristicValue + newNode->level;
                                aStarTree.push(newNode);
                            }
                        }
                    }
                    if (!aStarTree_parents.empty()) {
                        aStarTree_parents.pop();
                    }
                }
            }
        }
        orderAStarTree(children);
        do
        {
            currentNode = aStarTree.front();
            aStarTree.pop();
            aStarTree_parents.push(currentNode);

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
                    break;
                case 2:
                    if (game.verifyPlay(currentNode->color, 2)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: left reflexion of block with color " << currentNode->color << endl;

                        game.play(currentNode->color, 2);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 3:
                    if (game.verifyPlay(currentNode->color, 3)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: down reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 3);
                        b = game.getBoard();
                        nMoves++;
                    }
                    break;
                case 4:
                    if (game.verifyPlay(currentNode->color, 4)) {
                        cout << "\n\nTree level: " << currentNode->level;
                        cout << "\nMove: up reflexion of block with color " << currentNode->color << endl;
                        game.play(currentNode->color, 4);
                        b = game.getBoard();
                        nMoves++;
                    }
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
                game.getBoard().printBoard();
                return;
            }
        } while (!aStarTree.empty());
    } while (!game.endGame() || !game.checkVictory());
}

void orderAStarTree(vector<struct node *> &v){
    while (!aStarTree.empty()){
        v.push_back(aStarTree.front());
        aStarTree.pop();
    }
    while (!v.empty()){
        int id = getMinVal(v);
        aStarTree.push(v.at(id));
        v.erase(v.begin()+id);
    }
}

int getMinVal(vector<struct node *> &nodes){
    int low = 10000;
    int i;
    for (int j=0; j<(int)nodes.size(); j++)
    {
        int val = nodes.at(j)->value;
        if (val < low){
            low=val;
            i=j;
        }
    }
    return i;
}

float getHeuristicValue(Game game, int move, char blockColor, int heuristic)
{
    float val=0;
    int greedyValue = getGreedyValue(game, move,blockColor);

    //End game
    if (greedyValue == -1)
        return -1;

    switch (heuristic){
        //heuristic = nrColorfulPieces / greedyVal
        case 1:
            val = (float)getTotalPiecesBoard(game.getBoard()) / (float)greedyValue;
            break;

        //heuristic = greedyVal / nrColorfulPieces
        case 2:
            val = (float)greedyValue / (float)getTotalPiecesBoard(game.getBoard());
            break;

        //heuristic = greedyVal
        case 3:
            val = (float)greedyValue;
            break;
        default:
            break;
    }
    return val;
}

bool heuristicValueExist(vector<struct node*>v, float value){
    for(auto node: v){
        if (node->heuristicValue==value)
            return true;
    }
    return false;
}

