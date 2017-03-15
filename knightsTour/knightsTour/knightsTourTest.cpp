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
	unsigned int highestNumOfSolutions = 0;
	unsigned int userBoardSize = 0;
	unsigned int xYPos[2] = {};
	bool userPrintSolutions = false;
	bool userChoice;

	cout << "Welcome to the Knights Tour solver!" << endl;
	cout << "\nFind solution based on user given x,y position?[1] OR Find the best starting position?[0]" << endl;
	cout << "Please enter 1 OR 0: ";
	cin >> userChoice;

	cout << "\nPlease enter the required values. NOTE: all out of bound values will be set to defaults.";
	cout << "\n\nBoard size (must be between 0-10): ";
	cin >> userBoardSize;

	if (userChoice == true)
	{
		cout << "\n\nStarting position (row col) that fits within the board size of " << userBoardSize << "x" << userBoardSize << " : ";
		cin >> userStartPosY;
		cin >> userStartPosX;
		cout << "\n\nPrint game board Solutions? [1=true | 0=false]: ";
		cin >> userPrintSolutions;

		cout << "\n\nCalculating..." << endl;

		KnightsTour game1(userBoardSize, userStartPosX - 1, userStartPosY - 1);

		game1.printSolutions(userPrintSolutions);
	}
	else
	{
		KnightsTour game1(userBoardSize, 0, 0);

		cout << "\n\nCalculating..." << endl;

		highestNumOfSolutions = game1.findBestStartingPos(xYPos, userBoardSize);

		cout << "\n\nPostion (" << xYPos[0] << ", " << xYPos[1] << ") is the best starting point, with " << highestNumOfSolutions << " available solutions." << endl;
	}

	//Allow console to stay open
	cin.get();
	cin.ignore();

}