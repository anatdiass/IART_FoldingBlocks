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

    //TODO -> nao implementado
    void printIrregularBoard();

    Board();
    Board(int nRows, int nCols);

    /**
     * Return the number of rows of the board
     * @return Number of rows
     */
    int getNumRows();

    /**
     * Return the number of columns of the board
     * @return Number of columns
     */
    int getNumCols();

    /**
     * Set the color of a piece as '-'
     * @param row Vertical coordinate
     * @param col Horizontal coordinate
     */
    void deleteCell(int row, int col);

    /**
     * Creates an empty board game
     */
    void createEmptyBoard();

    /**
     * Prints the border of a single cell
     */
    static void printBorderCell();

    /**
     * Prints all the board horizontal lines
     */
    void printBorderLines();

    /**
     * Print columns indexes
     */
    void printHorizontalNumbers();

    /**
     * Print the entire board with cells content
     */
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
    static bool existPositionBlock(const vector<pair<int,int>>& positions, int row, int col);

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
     * Gets the block of a certain color
     * @param blockColor Color of block
     * @return Block
     */
    pair<char, vector<pair<int,int>>> getBlock(char blockColor);

    /**
     * Gets the block's cell with higher horizontal coordinate
     * @param positions All the positions of a block
     * @return Horizontal coordinate of the cell
     */
    static int getMostRightCell(const vector<pair<int,int>>& positions);

    /**
     * Gets the block's cell with lower horizontal coordinate
     * @param positions All the positions of a block
     * @return Horizontal coordinate of the cell
     */
    static int getMostLeftCell(const vector<pair<int,int>>& positions);

    /**
     * Gets the block's cell with lower vertical coordinate
     * @param positions All the positions of a block
     * @return Vertical coordinate of the cell
     */
    static int getMostUpCell(const vector<pair<int,int>>& positions);

    /**
     * Gets the block's cell with higher vertical coordinate
     * @param positions All the positions of a block
     * @return Vertical coordinate of the cell
     */
    static int getMostDownCell(const vector<pair<int,int>>& positions);

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

    /**
     * Right reflexion of all the pieces with the same color of indicated piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionBlockRight(int row, int col);

    /**
     * Left reflexion of all the pieces with the same color of indicated piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionBlockLeft(int row, int col);
    /**
     * Up reflexion of all the pieces with the same color of indicated piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionBlockUp(int row, int col);
    /**
     * Down reflexion of all the pieces with the same color of indicated piece
     * @param row Vertical coordinate of piece
     * @param col Horizontal coordinate of piece
     */
    void reflexionBlockDown(int row, int col);


};


#endif //UNTITLED_BOARD_H
