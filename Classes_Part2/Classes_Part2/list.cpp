#pragma once
/*
Program: list.cpp
Author: Demetri Van Sickle
Date: 2/3/17
Description: Contains the list class implementation code
*/
#include <iostream>
#include <string>
#include "list.h"

using namespace std;


List::List()
{
	//Initialize every string in the array to nothing (NULL)
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		items[itemIndx] = "";
	}

	totalItems = 0;
}


bool List::insert(string text)
{
	//Make sure the string given isnt null, isnt already in the list or the list is full
	if (text.empty() == true || inList(text) >= 0 || isFull() == true)
	{
		return false;
	}
	else
	{
		items[findEmpty()] = text;
		totalItems++;
		return true;
	}
}

bool List::remove(string text)
{
	int itemLocation = -1;
	int emptyLocation = 0;

	//Make sure that the string exsits and that the string given wasn't null
	if (inList(text) < 0 || text.empty() == true)
	{
		return false;
	}

	//Get the item location and delete it
	itemLocation = inList(text);
	items[itemLocation] = "";

	//while the deleted string wasn't the last item & the next item isn't empty, 
	while (itemLocation != (MAX_ITEMS - 1) && items[itemLocation + 1].empty() != true)
	{
		itemLocation++;
		emptyLocation = findEmpty();

		items[itemLocation].swap(items[emptyLocation]);
	}

	totalItems--;
	return true;
}

int List::inList(string textToFind) const
{
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		if (items[itemIndx] == textToFind)
		{
			return itemIndx;
		}
	}
	return -1;
}

//returns a bool value if the array is empty of not 
bool List::isEmpty() const
{
	//scan each string to see if it is empty
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		if (items[itemIndx].empty() != true)
		{
			return false;
		}
	}
	return true;
}

bool List::isFull() const
{
	if (totalItems == MAX_ITEMS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void List::print()
{
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		cout << items[itemIndx] << "  ";
	}
	cout << "\n";
}


int List::findEmpty() const
{
	//Find the first empty slot in the string array and return the indx number
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		if (items[itemIndx].empty() == true)
		{
			return itemIndx;
		}
	}
	return -1;
}
