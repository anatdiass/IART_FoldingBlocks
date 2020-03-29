#include <sstream>
#include "../include/Game.h"

Game::Game() {
    this->board=Board();
    this->validMoves=0;
}

int Game::nrValidMoves(){
    return validMoves;
}

void Game::calculateValidMoves(){
    this->validMoves=0;
    vector<pair<char, vector<int>>> validMoves = getNextValidMoves();
    for (auto & c : validMoves) {
        this->validMoves+=c.second.size();
    }
}

Board Game::getBoard(){
    return this->board;
}

vector<int> Game::getBlockNextValidMoves(char color){
    vector<int> validMoves;
    Board b = getBoard();

    if(b.verifyReflexionBlockRight(color)){
        validMoves.push_back(RIGTH);
    }
    if(getBoard().verifyReflexionBlockLeft(color)){
        validMoves.push_back(LEFT);
    }
    if(getBoard().verifyReflexionBlockDown(color)){
        validMoves.push_back(DOWN);
    }
    if(getBoard().verifyReflexionBlockUp(color)){
        validMoves.push_back(UP);
    }
    return validMoves;
}

vector<pair<char, vector<int>>> Game::getNextValidMoves(){
    vector<pair<char, vector<int>>> validMoves;

    vector<char> colors = getBoard().getBlocksColors();
    vector<int> colorMoves;
    pair<char, vector<int>> colorPair;

    for (auto & color : colors) {
        colorMoves = getBlockNextValidMoves(color);

        if(!colorMoves.empty()){
            colorPair = make_pair(color,colorMoves);
            validMoves.push_back(colorPair);
        }
    }


    return validMoves;
}

void Game::printValidMoves(){

    vector<pair<char, vector<int>>> validMoves = getNextValidMoves();

    //PRINT VALID MOVES
    if(validMoves.size()!=0) cout << "VALID MOVES " <<endl;

    for (auto & c : validMoves) {
        cout << "Color: " << c.first << endl;

        for (auto & d : c.second) {
            cout << "\tMove: ";
            if(d==1) cout << "right reflexion" << endl;
            else if(d==2) cout << "left reflexion\n";
            else if(d==3) cout << "down reflexion\n";
            else if(d==4) cout << "up reflexion\n";
        }
        cout << endl;
    }
}

bool Game::verifyPlay(char color, int move){
    vector<pair<char, vector<int>>> allMoves = getNextValidMoves();

    for (auto & blockMoves : allMoves) {

        if (blockMoves.first == color){

            bool found;

            for (auto & currMove : blockMoves.second) {
                if(currMove == move){
                    found = true;
                }
            }

            if(!found){
                cout << "Move not possible " << endl;
                return false;
            }
            else return true;
        }

    }
    cout << "Color not found " << endl;
    return false;
}

void Game::play(char color, int move){

    switch(move){
        case RIGTH:
            board.reflexionBlockRight(color);
            break;
        case LEFT:
            board.reflexionBlockLeft(color);
            break;
        case DOWN:
            board.reflexionBlockDown(color);
            break;
        case UP:
            board.reflexionBlockUp(color);
            break;
        default:
            break;
    }
    board.defineBlocks();
    calculateValidMoves();
}

bool Game::checkVictory() {
    for(int i=0;i<board.getNumRows();i++){
        for(int j=0;j<board.getNumCols();j++){
            char cellContent = board.getPieceColor(i,j);
            if(cellContent==' ')
                return false;
        }
    }
    return true;
}

bool Game::endGame() {
    if(getNextValidMoves().empty()){

        if(checkVictory()){
            cout << "YOU WON!!!" << endl;
        }
        else cout << "YOU LOST!!!" << endl;
        return true;

    }

    return false;
}

void Game::level1() {
    this->board=Board(4,4);
    this->board.setPiece(3,0,'R');
    board.defineBlocks();
}

void Game::level2(){
    this->board=Board(4,4);

    //Null cells
    board.deleteCell(0,1);
    board.deleteCell(0,2);
    board.deleteCell(1,0);
    board.deleteCell(1,3);
    board.deleteCell(2,0);
    board.deleteCell(2,3);
    board.deleteCell(3,1);
    board.deleteCell(3,2);

    board.setPiece(3,0,'A');
    board.setPiece(2,1,'A');

    board.defineBlocks();
}

void Game::level3(){
    this->board=Board(5,4);

    board.deleteCell(0,2);
    board.deleteCell(0,3);
    board.deleteCell(4,0);
    board.deleteCell(4,1);

    board.setPiece(0,0,'V');
    board.setPiece(4,2, 'A');

    board.defineBlocks();
}

void Game::level4(){
    this->board=Board(8,4);

    board.deleteCell(2,0);
    board.deleteCell(3,0);
    board.deleteCell(0,2);
    board.deleteCell(1,2);
    board.deleteCell(4,2);
    board.deleteCell(5,2);
    board.deleteCell(0,3);
    board.deleteCell(1,3);
    board.deleteCell(4,3);
    board.deleteCell(5,3);

    //Yellow pieces
    board.setPiece(0,0,'A');
    board.setPiece(0,1,'A');
    board.setPiece(1,0,'A');
    board.setPiece(1,1,'A');
    board.setPiece(2,3,'A');

    //Blue piece
    board.setPiece(2,2,'B');

    //Red piece
    board.setPiece(6,3,'V');

    board.defineBlocks();
}

void Game::chooseLevel() {
    int choice;
    cout << " ______________________________________ " << endl;
    cout << "|- Choose one of the available levels -|" << endl;
    cout << "| Level 1 (Warm Up)                    |" << endl;
    cout << "| Level 2 (Beginner)                   |" << endl;
    cout << "| Level 3 (Beginner)                   |" << endl;
    cout << "| Level 4 (Beginner)                   |" << endl;
    cout << "|______________________________________|" << endl;
    cout << "\nChoice: ";
    cin>>choice;

    switch(choice){
        case 1:
            level1();
            break;
        case 2:
            level2();
            break;
        case 3:
            level3();
            break;
        case 4:
            level4();
            break;
    }

}

void Game::loopGame() {

    char color;
    int  move;

    board.defineBlocks();
    do{

        board.printBoard();
        calculateValidMoves();
        cout << "Possible moves: " << nrValidMoves() << endl;
        printValidMoves();
        //Gets block by color
        cout << "\nChoose the color of your block: "; cin.ignore(1000, '\n');
        cin >> color;

        //check if color is valid
        while(!board.blockExists(color))
        {
            cin.clear();
            cin.ignore();
            cout << "Color does not exist!" << endl << "Choose the color of your block: ";
            cin>>color;
        }

        cout << "Choose one move\n";
        cout << RIGTH << " - Reflexion right\n";
        cout << LEFT << " - Reflexion left\n";
        cout << DOWN << " - Reflexion down\n";
        cout << UP << " - Reflexion up\n";
        cout << "Move: ";
        cin>>move;

        //check if move is valid
        while (!cin.good() || move < 1 || move > 4)
        {
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
            cout << "Not an option" << endl << "Choose one move: ";
            cin>>move;
        }

        if(verifyPlay(color,move)){
            play(color,move);
        }

    }while(!endGame());

    board.printBoard();
    cout << "\nEnd of game!\n";
}















