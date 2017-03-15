/*
Program: knightsTour.cpp
Author: Demetri Van Sickle
Date: 3/9/17
Description: Contains the list class implementation code
*/
#include <iostream>
#include <iomanip>
#include <assert.h>   
#include "knightsTour.h"

using namespace std;

KnightsTour::KnightsTour(unsigned int boardSize, unsigned int startingPosX, unsigned int startingPosY)
{
	//Reset boardSize if it's out of bounds
	if (boardSize > DEFAULT_BOARD_SIDE_LENGTH)
	{
		boardSize = DEFAULT_BOARD_SIDE_LENGTH;
	}
	else if (boardSize == 0)
	{
		boardSize = 2;
	}

	this->boardSize = boardSize;

	//Set the min & max values allowed for positions
	minPosLimit = 0;
	maxPosLimit = boardSize - 1;

	maxNumOfMoves = boardSize*boardSize;

	//Reset x & y positions if they are out of bounds
	if (startingPosX < minPosLimit || startingPosX > maxPosLimit)
	{
		startingPosX = boardSize / 2;
	}

	if (startingPosY < minPosLimit || startingPosY > maxPosLimit)
	{
		startingPosY = boardSize / 2;
	}

	this->startingPosX = startingPosX;
	this->startingPosY = startingPosY;
}

void KnightsTour::printSolutions(bool toPrint)
{
	cout << "Total # of Solutions: " << findSolutions(mainBoard, startingPosX, startingPosY, toPrint) << endl;
}

/*
NOTE:
	I know "findBestStartingPos" isn’t ideal, because there are multiple points with the same solution count and it doesn’t catch that,
	but this is mainly just to see if it could be done (and I also had some extra time).
*/
int KnightsTour::findBestStartingPos(unsigned int xYPos[], int boardSize)
{
	//unsigned int currentXY[1] = {};
	unsigned int currentNumOfSolutions = 0;
	unsigned int bestXYPos[2] = {};
	unsigned int highestNumOfSolutions = 0;

	//Cycle through all posible x,y postions and keep track of which x,y pair had the highest amount of solutions
	for (unsigned int row = 0; row < boardSize; row++)
	{
		for (unsigned int col = 0; col < boardSize; col++)
		{
			currentNumOfSolutions = findSolutions(mainBoard, row, col, false);

			if (currentNumOfSolutions > highestNumOfSolutions)
			{
				highestNumOfSolutions = currentNumOfSolutions;
				bestXYPos[0] = row + 1; //row
				bestXYPos[1] = col + 1; //col
			}
		}
	}
	xYPos[0] = bestXYPos[0];
	xYPos[1] = bestXYPos[1];
	return highestNumOfSolutions;
}

int KnightsTour::findSolutions(Board boardCopy, unsigned int posX, unsigned int posY, bool toPrint, unsigned int numberOfMoves)
{
	unsigned int totalValidSolutions = 0;
	unsigned int originalNum = 0;

	//if the position was out of bounds, or there is alreay a move at that position
	if ((posX < minPosLimit || posX > maxPosLimit) || (posY < minPosLimit || posY > maxPosLimit)
		|| (boardCopy.board[posY][posX] > 0))
	{
		return 0;
	}

	assert(numberOfMoves <= maxNumOfMoves);

	boardCopy.board[posY][posX] = numberOfMoves;

	//If board is full
	if (isFull(boardCopy) == true)
	{
		if (toPrint == true)
		{
			print(boardCopy);
		}
		return 1;
	}

	originalNum = numberOfMoves;

	totalValidSolutions += findSolutions(boardCopy, posX + 1, posY - 2, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findSolutions(boardCopy, posX + 2, posY - 1, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findSolutions(boardCopy, posX + 2, posY + 1, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findSolutions(boardCopy, posX + 1, posY + 2, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	//////////////////////////////////////////
	totalValidSolutions += findSolutions(boardCopy, posX - 1, posY - 2, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findSolutions(boardCopy, posX - 2, posY - 1, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findSolutions(boardCopy, posX - 2, posY + 1, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;
	totalValidSolutions += findSolutions(boardCopy, posX - 1, posY + 2, toPrint, ++numberOfMoves);
	numberOfMoves = originalNum;

	return totalValidSolutions;
}

void KnightsTour::print(Board boardCopy) const
{
	static unsigned int numOfSolutions = 1;

	cout << "\nSolution # " << numOfSolutions << ":" << endl;

	for (unsigned int row = 0; row < boardSize; row++)
	{
		for (unsigned int col = 0; col < boardSize; col++)
		{
			cout << setw(2) << setfill('0') << boardCopy.board[row][col] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
	numOfSolutions++;
}

bool KnightsTour::isFull(Board boardCopy) const
{
	for (unsigned int row = 0; row < boardSize; row++)
	{
		for (unsigned int col = 0; col < boardSize; col++)
		{
			if (boardCopy.board[row][col] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
