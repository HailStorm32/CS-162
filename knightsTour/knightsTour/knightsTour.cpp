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
#include "gameVariables.h"

using namespace std;

const int BOARD_WIDTH = 5;
const int BOARD_HEIGHT = 5;
const int START_POS_X = 2;
const int START_POS_Y = 2;



struct KnightsTour
{
	int board[BOARD_WIDTH][BOARD_HEIGHT] = {};
	int startingPos;
};

int findKnightsTour(KnightsTour game, int posX, int posY);

void main()
{
	KnightsTour game1;

	game1.startingPos = 

	findKnightsTour(game1, )



}

int findKnightsTour(KnightsTour game, int posX, int posY)
{
	
	
	return 0;
}
