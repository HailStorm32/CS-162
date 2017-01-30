#include <iostream>
#include <string>
#include "list.h"

using namespace std;

List::List()
{
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		listContents[itemIndx] = "";
	}

	totalItems = 0;
}

bool List::insert(string text)
{
	if (text.empty() == true || inList(text) == true || totalItems == MAX_ITEMS)
	{
		return false;
	}
	else
	{

		totalItems++;
		return true;
	}
}

bool List::remove(string text)
{
	return false;
}

bool List::inList(string text) const
{
	if (text.empty() == true)
	{
		return true;
	}

	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		if (listContents[itemIndx].find(text) != string::npos)
		{
			return true;
		}
	}
	return false;
}

bool List::isEmpty() const
{
	for (int itemIndx = 0; itemIndx < MAX_ITEMS; itemIndx++)
	{
		if (listContents[itemIndx].empty() == false)
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
}
