/*
Program: knightsTour.cpp
Author: Demetri Van Sickle
Date: 3/9/17
Description: Find solutions for a Knights Tour board. Uses brute force and prints out all board solutions
*/
/*
================= psuedo code ===================
findKnightsTour
	If move (i.e. x and y values) invalid
		return 0
	put moveNumber on board
	If board is full  <---Base case
		print board
		return 1
	Call findKnightsTour 8 more times with the 8 possible moves, and returned result to TotalValidSolutions

	return TotalValidSolutions;
*/
#include <iostream>
#include <iomanip>
#include <assert.h>   

using namespace std;

const int BOARD_SIDE_LENGTH = 5;
const int DEFAULT_START_POS_X = 4;
const int DEFAULT_START_POS_Y = 0;

const int MIN_LIMIT = 0;
const int MAX_LIMIT = BOARD_SIDE_LENGTH - 1;
const int MAX_NUM_OF_MOVES = BOARD_SIDE_LENGTH * BOARD_SIDE_LENGTH;



struct KnightsTour
{
	int board[BOARD_SIDE_LENGTH][BOARD_SIDE_LENGTH] = {};
	int startingPosX = DEFAULT_START_POS_X;
	int startingPosY = DEFAULT_START_POS_Y;
};

void printBoard(const KnightsTour game);
int findKnightsTour(KnightsTour game, int posX, int posY, int numberOfMoves=1);

void main()
{
	KnightsTour game1;

	cout << "Finding paths...\n" << endl;

	cout << "Total # of Solutions: " << findKnightsTour(game1, game1.startingPosX, game1.startingPosY) << endl;

	//Allow console to stay open
	cin.get();
	cin.ignore();

}


//==========================================================
// Function: printBoard
// Description: 
//		print out the solved knights tour board
//
// Arguments:
//		game (I) -- board that contains all the moves
// Returns:
//		NONE
//==========================================================
void printBoard(const KnightsTour game)
{
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			cout << setw(2) << setfill('0') << game.board[row][col] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
}

//===========================================================
// Function: boardIsFull
// Description: Sees if the gameboard is full of valid moves
//
// Arguments:
//		game (I) -- board that contains all the moves
// Returns:
//		True -- if board is full
//		False -- if board is NOT full
//===========================================================
bool boardIsFull(const KnightsTour game)
{
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
		{
			if (game.board[row][col] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

//========================================================================================
// Function: findKnightsTour
// Description:  
//		Recursively solves the knights tour using brute force.  
//		Prints any solutions if finds.
// Arguments:
//		game (I/O) -- the board we’re working with 
//		posX (I) -- the row we’re going to attempt to place the knight on this move.
//		posY (I) -- the column we’re going to attempt place the knight on this move.
//		numberOfMoves (I) -- the move we’re making
// Returns: 
//		totalValidSolutions -- The number of solutions the given board and move leads to
//========================================================================================
int findKnightsTour(KnightsTour game, int posX, int posY, int numberOfMoves)
{
	unsigned int totalValidSolutions = 0;
	unsigned int originalNum = 0;
	
	//if the position was out of bounds, or there is alreay a move at that position
	if ((posX < MIN_LIMIT || posX > MAX_LIMIT) || (posY < MIN_LIMIT || posY > MAX_LIMIT)
		|| (game.board[posY][posX] > 0))
	{
		return 0;
	}

	assert(numberOfMoves <= MAX_NUM_OF_MOVES);

	game.board[posY][posX] = numberOfMoves;

	//If board is full
	if (boardIsFull(game) == true)
	{
		printBoard(game);
		return 1;
	}

	originalNum = numberOfMoves;

	totalValidSolutions += findKnightsTour(game, posX + 1, posY - 2, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findKnightsTour(game, posX + 2, posY - 1, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findKnightsTour(game, posX + 2, posY + 1, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findKnightsTour(game, posX + 1, posY + 2, ++numberOfMoves);
	numberOfMoves = originalNum;
	//////////////////////////////////////////
	totalValidSolutions += findKnightsTour(game, posX - 1, posY - 2, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findKnightsTour(game, posX - 2, posY - 1, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findKnightsTour(game, posX - 2, posY + 1, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findKnightsTour(game, posX - 1, posY + 2, ++numberOfMoves);
	numberOfMoves = originalNum;

	return totalValidSolutions;
}

