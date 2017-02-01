#include <iostream>
#include "list.h"
#include <string>

using namespace std;

char getUserChoice();

void main()
{
	List list1;
	string userInput = "";
	char userChoice = ' ';

	cout << "You have a list that can hold " << MAX_ITEMS << " items. No duplicates.\n\n";

	list1.print();

	userChoice = getUserChoice();

	while (userChoice != 'E')
	{
		switch (userChoice)
		{
		case 'A':
			cout << "Please enter the text you want to add, and press enter when done: ";
			cin >> userInput;

			if (list1.insert(userInput) == true)
			{
				cout << "\nAdded!" << endl;
			}
			else
			{
				cout << "\nFailed!" << endl;
			}
			break;

		case 'R':
			cout << "Please enter the item you would like to remove (exactly like it was entered): ";
			cin >> userInput;

			if (list1.remove(userInput) == true)
			{
				cout << "\nRemoved!" << endl;
			}
			else
			{
				cout << "\nFailed!" << endl;
			}
			break;

		case 'P':
			cout << "\nPrinting out list:" << endl;

			list1.print();
			break;
		}
		userChoice = getUserChoice();
	}
}


//==========================================================
// Function: getUserChoice
// Description: Get the action the user wants to do on the 
//				list
//	
// Arguments:
//		NONE
// Return Values:
//		userChoice --  A, R, P or E
//===========================================================
char getUserChoice()
{
	char userChoice = ' ';
	bool exitFlag = false;

	while (exitFlag == false)
	{
		cout << "\n\nWhat would you like to do?\n\n";
		cout << "[A]dd item, [R]emove item, [P]rint list, [E]xit: ";
		cin >> userChoice;

		if (toupper(userChoice) == 'A' || toupper(userChoice) == 'R' || toupper(userChoice) == 'P' || toupper(userChoice) == 'E')
		{
			exitFlag = true;
		}
		else
		{
			cout << "Data entered is invalid! Please enter a P, R, or E" << endl;
		}
	}
	return toupper(userChoice);
}