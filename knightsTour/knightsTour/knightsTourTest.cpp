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
#include "knightsTour.h"

using namespace std;

void main()
{
	unsigned int userStartPosX = 0;
	unsigned int userStartPosY = 0;
	unsigned int userBoardSize = 0;
	bool userPrintSolutions = false;

	cout << "Welcome to the Knights Tour solver!" << endl;
	cout << "Please enter the required values. NOTE: all out of bound values will be set to defaults.";
	cout << "\n\nBoard size (must be between 0-10): ";
	cin >> userBoardSize;
	cout << "\n\nStarting position (row col) that fits within the board size of " << userBoardSize << "x" << userBoardSize << " : ";
	cin >> userStartPosY;
	cin >> userStartPosX;
	cout << "\n\nPrint game board Solutions? [1=true | 0=false]: ";
	cin >> userPrintSolutions;
	cout << "\n\nCalculating..." << endl;

	KnightsTour game1(userBoardSize, userStartPosX - 1, userStartPosY - 1);

	game1.printSolutions(userPrintSolutions);

	//Allow console to stay open
	cin.get();
	cin.ignore();

}