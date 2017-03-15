#pragma once
/*
Program: knightsTour.h
Author: Demetri Van Sickle
Date: 3/9/17
Description: Contains the list class definition code
*/

//Set a default board size that we can "crop" for smaller sizes
const unsigned int DEFAULT_BOARD_SIDE_LENGTH = 10;

struct Board
{
	int board[DEFAULT_BOARD_SIDE_LENGTH][DEFAULT_BOARD_SIDE_LENGTH] = {};
};

class KnightsTour
{
public:
	/*
	Input:
		boardSize -- non-negative integer > 0 & <= DEFAULT_BOARD_SIDE_LENGTH
		startingPosX -- non-negative integer within boardSize
		startingPosY -- non-negative integer within boardSize
	*/
	KnightsTour(unsigned int boardSize, unsigned int startingPosX, unsigned int startingPosY);

	/*
	Input:
		toPrint -- bool value
	*/
	void printSolutions(bool toPrint);

	/*
	Input:
		boardSize -- size of board to work with
	Output:
		xYPos (O) -- x & y position of best starting spot
		totalValidSolutions -- number of valid solutions
	*/
	int findBestStartingPos(unsigned int xYPos[], int boardSize);

private:
	/*
	Input:
		Board -- copy of the board struct
	*/
	void print(Board boardCopy) const;

	/*
	Input:
		Board -- copy of the board struct
	Returns:
		True -- if board is full of moves
		False -- if board is NOT full of moves
	*/
	bool isFull(Board boardCopy) const;

	/*
	Input:
		Board -- copy of the board struct
		posX -- non-negative integer within boardSize
		posY -- non-negative integer within boardSize
		toPrint -- bool value
		numberOfMoves -- non-negative integer within boardSize*boardSize
	Returns:
		totalValidSolutions -- number of valid solutions
	*/
	int findSolutions(Board boardCopy, unsigned int posX, unsigned int posY, bool toPrint, unsigned int numberOfMoves = 1);

	unsigned int startingPosX;
	unsigned int startingPosY;
	unsigned int minPosLimit;
	unsigned int maxPosLimit;
	unsigned int maxNumOfMoves;
	unsigned int boardSize;
	Board mainBoard;
};