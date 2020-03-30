#include <iostream>

#include "Algorithms.h"
#include "Game.h"

using namespace std;

void selectMode(Game game){
    int choice;
    cout << " ____________________ " << endl;
    cout << "|- Choose game mode -|" << endl;
    cout << "| 1 - Player         |" << endl;
    cout << "| 2- AI              |" << endl;
    cout << "|____________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    switch(choice){
        case 1:
            game.chooseLevel();
            game.loopGame();
            break;
        case 2:
            game.chooseLevel();
            selectAlgorithm(game);
            break;
        default:
            break;
    }
}

void selectAlgorithm(Game game){
    int choice;
    cout << " __________________________________" << endl;
    cout << "|-      Choose the algorithm      -|" << endl;
    cout << "| 1 - BFS (Breadth First Search)   |" << endl;
    cout << "| 2 - DFS (Depth First Search)     |" << endl;
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
