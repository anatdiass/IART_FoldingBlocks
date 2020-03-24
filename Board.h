#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Board {
public:
private:
    int nRows;
    int nCols;
    vector<vector<char>> board;
    vector<pair<char,vector<pair<int,int>>>>blocks;
public:

    Board(int nRows, int nCols);

    void createEmptyBoard();
    void printBorderCell();
    void printBorderLines();
    void printHorizontalNumbers();
    void printBoard();

    /**
     * Defines a color for specific position
     * @param row Vertical coordinate
     * @param col Horizontal coordinate
     * @param color Color of piece
     */
    void setPiece(int row, int col, char color);

    /**
     * Returns the color of a specific position
     * @param row Vertical coordinate
     * @param col Horizontal coordinate
     * @return Color of piece
     */
    char getPieceColor(int row, int col);

    /**
     * Verify if the block of a certain color was already created
     * @param index Color of block
     * @return True if the block was already created
     */
    bool blockExists(char index);

    /**
     * Create a new block for the specified color
     * @param indexChar Color of block
     */
    void createBlock(char indexChar);

    /**
     * Verify if a position was already added to the block
     * @param positions Positions of all the block's pieces
     * @param row Vertical coordinate of new piece
     * @param col Horizontal coordinate of new piece
     * @return True if the position of new piece was already added to the block
     */
    bool existPositionBlock(vector<pair<int,int>> positions, int row, int col);

    /**
     * Add a new piece to an existing block
     * @param indexChar Color of block
     * @param row Vertical coordinate of new piece
     * @param col Horizontal coordinate of new piece
     */
    void updateBlock(char indexChar, int row, int col);

    /**
     * Creates all blocks existing on the game board and add them to the blocks structure
     */
    void defineBlocks();

    /**
     * Returns the blocks of board
     * @return Board's blocks
     */
    vector<pair<char,vector<pair<int,int>>>> getBlocks();


    /**
     * Right reflexion of a single piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionRight(int row, int col);

    /**
     * Left reflexion of a single piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionLeft(int row, int col);

    /**
     * Up reflexion of a single piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionUp(int row, int col);

    /**
     * Down reflexion of a single piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionDown(int row, int col);

};


#endif //UNTITLED_BOARD_H
