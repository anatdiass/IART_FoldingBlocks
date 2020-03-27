#include "Board.h"

/*CONSTRUCTOR*/

void Board::printIrregularBoard(){
    //TODO -> se possível
}


Board::Board() {
    this->nRows=0;
    this->nCols=0;
}

Board::Board(int nRows, int nCols) : nRows(nRows), nCols(nCols) {
    createEmptyBoard();
}

vector<vector<char>> getBoard(){
    return this->board;
}

int Board::getNumRows() {
    return this->nRows;
}

int Board::getNumCols() {
    return this->nCols;
}

void Board::deleteCell(int row, int col) {
    setPiece(row, col, '-');
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
    for(auto & block : blocks){
        if(block.first==index)
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

bool Board::existPositionBlock(const vector<pair<int,int>>& positions, int row, int col) {
    pair<int,int>position;
    position.first=row;
    position.second=col;
    for(const auto & i : positions){
        if(i==position)
            return true;
    }
    return false;
}

void Board::updateBlock(char indexChar, int row, int col) {
    for(auto & block : blocks){
        if(block.first==indexChar){
            pair<int,int> pos;
            pos.first=row;
            pos.second=col;
            if(!existPositionBlock(block.second, row, col))
                block.second.push_back(pos);
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
    if(blockExists(blockColor)) {
        for (auto & block : blocks) {
            if (block.first == blockColor)
                return block;
        }
    }

    pair<char,vector<pair<int,int>>> nullPair;
    pair<int,int> null;
    null.first=-1;null.second=-1;
    vector<pair<int,int>> nullVec; nullVec.push_back(null);
    nullPair.first=(char)0;
    nullPair.second=nullVec;
    return nullPair;

}

int Board::getMostRightCell(const vector<pair<int,int>>& positions){
    int maxX=0;
    for(auto & position : positions){
        if(position.second>maxX)
            maxX=position.second;
    }
    return maxX;
}

int Board::getMostLeftCell(const vector<pair<int,int>>&positions){
    int minX;
    for(auto & position : positions){
        if(position.second<minX)
            minX=position.second;
    }
    return minX;
}

int Board::getMostUpCell(const vector<pair<int, int>>& positions) {
    int minY;
    for(auto &position: positions){
        if(position.first<minY)
            minY=position.first;
    }
    return minY;
}

int Board::getMostDownCell(const vector<pair<int, int>>& positions) {
    int maxY=0;
    for(auto &position: positions){
        if(position.first>maxY)
            maxY=position.first;
    }
    return maxY;
}

/*REFLEXION FUNCTIONS*/
bool Board::reflexionRight(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' ' || nCols<=col)
        return false;

    if(getPieceColor(row, col+1)==' ' && getPieceColor(row,col+1)!='-')
        setPiece(row, col+1, cellContent);

    return true;
}

bool Board::reflexionLeft(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' '  || col==1)
        return false;

    if(getPieceColor(row, col-1)==' ' && getPieceColor(row,col-1)!='-')
        setPiece(row, col-1, cellContent);

    return true;
}

bool Board::reflexionUp(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' '  || row==1)
        return false;

    if(getPieceColor(row-1,col)==' ' &&getPieceColor(row-1,col)!='-')
        setPiece(row-1, col, cellContent);

    return true;
}

bool Board::reflexionDown(int row, int col) {
    char cellContent = getPieceColor(row,col);
    if(cellContent==' ' || nRows<=row)
        return false;

    if(getPieceColor(row+1,col)==' ' && getPieceColor(row+1,col)!='-')
        setPiece(row+1,col,cellContent);

    return true;
}

bool Board::reflexionBlockRight(int row, int col) {
    char pieceColor = getPieceColor(row,col);

    if(pieceColor==' ')
        return false;

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
            return false;
        else{
            //Verify the destination pieces
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int pieceColumn = piece.second;
                int distToMRC = indexMostRightCell - pieceColumn;
                int deltaX = (2*distToMRC) + 1;
                char destinationCell = getPieceColor(piece.first,pieceColumn+deltaX);
                if(destinationCell != ' ' || destinationCell=='-')
                    return false;
            }
            //Do reflexion
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int pieceColumn = piece.second;
                int distToMRC = indexMostRightCell - pieceColumn;
                int deltaX = (2*distToMRC) + 1;
                setPiece(piece.first, pieceColumn+deltaX, pieceColor);
            }
        }
    }
    return true;
}

bool Board::reflexionBlockLeft(int row, int col) {
    char pieceColor = getPieceColor(row,col);

    if(pieceColor==' ')
        return false;

    pair<char, vector<pair<int,int>>> block = getBlock(pieceColor);
    int nrPieces = block.second.size();

    if(nrPieces==1)
        reflexionLeft(row,col);

    else {
        int indexMostRightCell = getMostRightCell(block.second);
        int indexMostLeftCell = getMostLeftCell(block.second);
        int compBetweenCells = indexMostRightCell-indexMostLeftCell;
        //verify if the reflexion is possible
        if((indexMostRightCell-(2*compBetweenCells+1))<0)
            return false;
        else{
            //Verify the destination pieces
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int pieceColumn=piece.second;
                int distToMLC =  pieceColumn-indexMostLeftCell;
                int deltaX = (2*distToMLC)+1;
                char destinationCell = getPieceColor(piece.first,pieceColumn-deltaX);
                if(destinationCell != ' ' || destinationCell=='-')
                    return false;
            }
            //Do reflexion
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col

                int pieceColumn=piece.second;
                int distToMLC =  pieceColumn-indexMostLeftCell;
                int deltaX = (2*distToMLC)+1;

                setPiece(piece.first, pieceColumn-deltaX, pieceColor);
            }
        }
    }

    return true;
}

bool Board::reflexionBlockUp(int row, int col) {
    char pieceColor = getPieceColor(row,col);

    if(pieceColor==' ')
        return false;

    pair<char, vector<pair<int,int>>> block = getBlock(pieceColor);
    int nrPieces = block.second.size();

    if(nrPieces==1)
        reflexionUp(row,col);

    else {
        int indexMostDownCell = getMostDownCell(block.second);
        int indexMostUpCell = getMostUpCell(block.second);
        int heightBetweenCells = indexMostDownCell-indexMostUpCell;
        //verify if the reflexion is possible
        if((indexMostDownCell-(2*heightBetweenCells+1))<0)
            return false;
        else{
            //Verify the destination pieces
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int pieceRow=piece.first;
                int distToMUC =  pieceRow-indexMostUpCell;
                int deltaY = (2*distToMUC)+1;
                char destinationCell = getPieceColor(pieceRow-deltaY,piece.second);
                if(destinationCell != ' ' || destinationCell=='-')
                    return false;
            }
            //Do reflexion
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col

                int pieceRow=piece.first;
                int distToMUC =  pieceRow-indexMostUpCell;
                int deltaY = (2*distToMUC)+1;

                setPiece(pieceRow-deltaY, piece.second, pieceColor);
            }
        }
    }
    return true;
}

bool Board::reflexionBlockDown(int row, int col) {
    char pieceColor = getPieceColor(row,col);

    if(pieceColor==' ')
        return false;

    pair<char, vector<pair<int,int>>> block = getBlock(pieceColor);
    int nrPieces = block.second.size();

    if(nrPieces==1)
        reflexionDown(row,col);

    else {
        int indexMostDownCell = getMostDownCell(block.second);
        int indexMostUpCell = getMostUpCell(block.second);
        int heightBetweenCells = indexMostDownCell-indexMostUpCell;
        //verify if the reflexion is possible
        if((indexMostUpCell+(2*heightBetweenCells)+1)>=nCols)
            return false;
        else{
            //Verify the destination pieces
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int pieceRow = piece.first;
                int distToMDC = indexMostDownCell - pieceRow;
                int deltaY = (2*distToMDC) + 1;
                char destinationCell = getPieceColor(pieceRow+deltaY,piece.second);
                if(destinationCell != ' ' || destinationCell=='-')
                    return false;
            }
            //Do reflexion
            for(int i=0;i<nrPieces;i++){
                pair<int,int>piece = block.second[i];   //piece.first -> row, piece.second->col
                int pieceRow = piece.first;
                int distToMDC = indexMostDownCell - pieceRow;
                int deltaY = (2*distToMDC) + 1;
                setPiece(pieceRow+deltaY, piece.second, pieceColor);
            }
        }
    }
    return true;
}
