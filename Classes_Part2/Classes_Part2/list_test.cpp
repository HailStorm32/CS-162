/*
Program: list_test.cpp
Author: Demetri Van Sickle
Date: 2/3/17
Description: Use the list class and have the user change the contents of the list
*/
#include <iostream>
#include <fstream>
#include "list.h"
#include <string>

using namespace std;

const string FILE_NAME = "listdata.txt";
const int DATA_SIZE = 100;

char interpretData(const char lineData[], string& dataToWrite);
bool executeCommand(const string& data, char command, List& list1);

int main()
{
	List list1;
	ifstream fileRead;

	char command = ' ';
	char lineText[DATA_SIZE] = {};
	string listData = "";


	fileRead.open(FILE_NAME);

	//If file cant be opened, report it
	if (!fileRead.is_open())
	{
		cout << "\nError! Cant open file " << FILE_NAME << endl;
		cout << "Aborting program!" << endl;
		return -1;
	}

	//Read the commands and data off the file
	while (!fileRead.eof())
	{
		fileRead.getline(lineText, DATA_SIZE);

		command = interpretData(lineText, listData);

		executeCommand(listData, command, list1);
	}

	fileRead.close();
}


//=========================================================================
// Function: interpretData
// Description: Interpret the given sting and separate the 
//				command and data string
//
// Arguments: 
//		lineData (I) -- cstring that contains both the commandand and the data to 
//						write and needs to be interpreted
//		dataToWrite (O) -- cstring that has been separated from the command
//						   and ready to write to list
// Return Values:
//		command -- char command value of A,R,F or P
//==========================================================================
char interpretData(const char lineData[], string& dataToWrite)
{
	char command = ' ';

	command = lineData[0];

	dataToWrite = lineData;
	dataToWrite.erase(0, 2);

	return toupper(command);
}


//=========================================================================
// Function: executeCommand
// Description: Execute the given command
//
// Arguments: 
//		dataToWrite (I) -- cstring data to write to list
//		command (I) -- char command value of A,R,F or P
//		list1 (O) -- import list1 member
// Return Values:
//		bool
//			True -- is successful 
//			False -- NOT successful
//==========================================================================
bool executeCommand(const string& data, char command, List& list1)
{
	switch (command)
	{
	case 'A':
		if (list1.insert(data))
		{
			cout << "Add:\t" << data << endl;
		}
		else
		{
			cout << "Add:\t" << data << " -- FAILED" << endl;
		}
		break;
	case 'R':
		if (list1.remove(data))
		{
			cout << "Remove:\t" << data << endl;
		}
		else
		{
			cout << "Remove:\t" << data << " -- FAILED" << endl;
		}
		break;
	case 'F':
		if (list1.inList(data) >= 0)
		{
			cout << "Find:\t" << data << endl;
		}
		else
		{
			cout << "Find:\t" << data << " -- FAILED" << endl;
		}
		break;
	case 'P':
		cout << "Print:  ";
		list1.print();
		break;
	default:
		cout << "ERROR:  invalid command: " << command << endl;
		return false;
		break;
	}
	return true;
}




