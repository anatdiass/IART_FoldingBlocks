#include <iostream>

#include "Algorithms.h"
#include "Game.h"

using namespace std;

void selectAStarFunction(Game game){
    int choice;
    cout << " ____________________________" << endl;
    cout << "|-Select heuristics function-|" << endl;
    cout << "| 1.                         |" << endl;
    cout << "| 2.                         |" << endl;
    cout << "| 3.                         |" << endl;
    cout << "|____________________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    aStar(game, choice);
}

void selectAlgorithm(Game game){
    int choice;
    cout << " __________________________________" << endl;
    cout << "|-      Choose the algorithm      -|" << endl;
    cout << "| 1 - BFS (Breadth First Search)   |" << endl;
    cout << "| 2 - DFS (Depth First Search)     |" << endl;
    cout << "| 3 - Greedy Algorithm             |" << endl;
    cout << "| 4 - A* Algorithm                 |" << endl;
    cout << "|__________________________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    switch(choice){
        case 1:
            bfs(game);
            break;
        case 2:
            dfs(game);
            break;
        case 3:
            greedy(game);
            break;
        case 4:
            selectAStarFunction(game);
            break;
        default:
            break;
    }
}

void selectMode(Game game){
    int choice;
    cout << " ____________________________ " << endl;
    cout << "|-     Choose game mode     -|" << endl;
    cout << "| 1 - Player(w/tips)         |" << endl;
    cout << "| 2 - Player                 |" << endl;
    cout << "| 3- AI                      |" << endl;
    cout << "|____________________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    switch(choice){
        case 1:
            game.chooseLevel();
            game.loopGame(true);
            break;
        case 2:
            game.chooseLevel();
            game.loopGame(false);
            break;
        case 3:
            game.chooseLevel();
            selectAlgorithm(game);
            break;
        default:
            break;
    }
}

int main() {
    cout << " ------------------------------------------------------------ " << endl;
    cout << "                  WELCOME TO FOLDING BLOCKS!                  " << endl;
    cout << " ------------------------------------------------------------ " << endl;

    Game game;
    selectMode(game);
    return 0;
}
