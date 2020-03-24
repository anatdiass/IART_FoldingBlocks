#include "Board.h"

/*CONSTRUCTOR*/
Board::Board(int nRows, int nCols) : nRows(nRows), nCols(nCols) {
    createEmptyBoard();
}

/*BUILD BOARD*/
void Board::createEmptyBoard() {
    for(int i = 0; i < nRows; i++){
        std::vector<char> temp;
        for(int j = 0; j < nCols; j++){
            temp.push_back(' ');
        }
        board.push_back(temp);
    }
}

/*PRINT BOARD*/
void Board::printBorderCell() {
    cout << "_____.";
}

void Board::printBorderLines() {
    cout << "   .";
    for (int i=0; i<nCols; i++){
        printBorderCell();
    }
}

void Board::printHorizontalNumbers() {
    cout << "\n ";
    for(int i=0;i<nCols;i++){
        cout << "     "<<i;
    }
    cout << "\n";
}

void Board::printBoard() {

    printHorizontalNumbers();
    printBorderLines();
    for(int i=0;i<nRows;i++){

        //Print row indice
        cout<<"\n" << i;
        cout << ((i) < 10 ? "  |" : " |");

        //Print cell color
        for(int j=0;j<nCols;j++){
            cout << "  "<< getPieceColor(i, j)<<"  |";
        }

        cout << "\n";
        printBorderLines();
        cout << "\n";
    }
}


/*MANAGE BOARD*/

void Board::setPiece(int row, int col, char color){
    if(row>=0 && col>=0 && row<nRows && col<nCols)
        board.at(row).at(col) = color;
}

char Board::getPieceColor(int row, int col) {
    if(row>=0 && col>=0 && row<nRows && col<nCols)
        return board.at(row).at(col);
    else return (char)0;
}

bool Board::blockExists(char index) {
    for(int i=0;i<blocks.size();i++){
        if(blocks[i].first==index)
            return true;
    }
    return false;
}

void Board::createBlock(char indexChar) {
    pair<char,vector<pair<int,int>>> block;
    block.first=indexChar;

    vector<pair<int,int>> positions;
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            char cellContent = getPieceColor(i,j);
            if(cellContent == indexChar){
                pair<int,int> pos;
                pos.first=i;
                pos.second=j;
                positions.push_back(pos);
            }
        }
    }
    block.second=positions;
    blocks.push_back(block);
}

bool Board::existPositionBlock(vector<pair<int,int>> positions, int row, int col) {
    pair<int,int>position;
    position.first=row;
    position.second=col;
    for(int i=0;i<positions.size();i++){
        if(positions[i]==position)
            return true;
    }
    return false;
}

void Board::updateBlock(char indexChar, int row, int col) {
    for(int i=0;i<blocks.size();i++){
        if(blocks[i].first==indexChar){
            pair<int,int> pos;
            pos.first=row;
            pos.second=col;
            if(!existPositionBlock(blocks[i].second, row, col))
                blocks[i].second.push_back(pos);
        }
    }
}


void Board::defineBlocks() {
    for (int row=0;row<nRows;row++){
        for(int col=0;col<nCols;col++){
            char cellContent = getPieceColor(row,col);
            if(cellContent!=' '){
                //new block
                if(!blockExists(cellContent)){
                    createBlock(cellContent);
                }
                //Add to existing block
                else{
                    updateBlock(cellContent,row,col);
                }
            }
        }
    }
}

vector<pair<char, vector<pair<int, int>>>> Board::getBlocks() {
    return blocks;
}

pair<char, vector<pair<int,int>>> Board::getBlock(char blockColor){
    if(blockExists(blockColor))
        for(int i=0;i<blocks.size();i++){
            if(blocks[i].first==blockColor)
                return blocks[i];
        }
}

int Board::getMostRightCell(vector<pair<int,int>> positions){
    int maxX=0;
    for(int i=0;i<positions.size();i++){
        if(positions[i].second>maxX)
            maxX=positions[i].second;
    }
    return maxX;
}

int Board::getMostLeftCell(vector<pair<int,int>>positions){
    int minX;
    for(int i=0;i<positions.size();i++){
        if(positions[i].second<minX)
            minX=positions[i].second;
    }
    return minX;
}

/*REFLEXION FUNCTIONS*/
void Board::reflexionRight(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' ' || nCols<=col)
        return;

    if(getPieceColor(row, col+1)==' ')
        setPiece(row, col+1, cellContent);
}

void Board::reflexionLeft(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' '  || col==1)
        return;

    if(getPieceColor(row, col-1)==' ')
        setPiece(row, col-1, cellContent);
}

void Board::reflexionUp(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' '  || row==1)
        return;

    if(getPieceColor(row-1,col)==' ')
        setPiece(row-1, col, cellContent);
}

void Board::reflexionDown(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' ' || nRows<=row)
        return;

    if(getPieceColor(row+1,col)==' ')
        setPiece(row+1,col,cellContent);
}

void Board::reflexionBlockRight(int row, int col) {
    char pieceColor = getPieceColor(row,col);

    if(pieceColor==' ')
        return;

    pair<char, vector<pair<int,int>>> block = getBlock(pieceColor);
    int nrPieces = block.second.size();

    if(nrPieces==1)
        reflexionRight(row,col);

    else {
        int indexMostRightCell = getMostRightCell(block.second);
        int indexMostLeftCell = getMostLeftCell(block.second);
        int compBetweenCells = indexMostRightCell-indexMostLeftCell;
        //verify if the reflexion is possible
        if((indexMostLeftCell+(2*compBetweenCells)+1)>=nCols)
            return;
        else{
            //Do reflexion
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int distToMRC = indexMostRightCell - piece.second;
                setPiece(piece.first, (2*distToMRC)+1+piece.second, 'b');
            }
        }
    }
}













