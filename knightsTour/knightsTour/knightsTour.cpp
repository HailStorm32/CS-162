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
	for (unsigned int row = 0; row < boardSize; row++)
	{
		for (unsigned int col = 0; col < boardSize; col++)
		{
			cout << setw(2) << setfill('0') << boardCopy.board[row][col] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
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
