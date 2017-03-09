/*
Program: LinkList.cpp
Author: Demetri Van Sickle
Date: 3/2/17
Description: Contains LinkList implementation code
*/
#include <iostream>
#include "LinkList.h"

using namespace std;

LinkList::LinkList()
{
	head = NULL;
	itemsInList = 0;
}

LinkList::~LinkList()
{

}

bool LinkList::insert(const string nameToInsert)
{
	Node* currentNode = NULL;
	Node* previousNode = NULL;

	//Make sure given string isnt empty and that that string hasnt already been entered
	if (nameToInsert.empty() == true || find(nameToInsert) > 0)
	{
		return false;
	}

	//Create new node
	Node* newNode = new Node;
	newNode->name = nameToInsert;
	newNode->nextNodeAddress = NULL;

	//If list is empty, 
	if (head == NULL)
	{
		head = newNode;
		itemsInList++;
		return true;
	}

	currentNode = head;

	//Cycle until we find a word in the list that goes BEFORE our nameToInsert OR we reach the end of the list
	while (insertAfter(nameToInsert, currentNode->name) == true && currentNode->nextNodeAddress != NULL)
	{
		//Store the current as the previous
		previousNode = currentNode;

		//Advance to the next node
		currentNode = currentNode->nextNodeAddress;
	}



	//If we got to the end of the list and nameToInsert can be put AFTER the currentname
	if (currentNode->nextNodeAddress == NULL && insertAfter(nameToInsert, currentNode->name) == true)
	{
		currentNode->nextNodeAddress = newNode;

		itemsInList++;
		return true;
	}
	//If the first item
	else if (previousNode == NULL)
	{
		head = newNode;

		newNode->nextNodeAddress = currentNode;

		itemsInList++;
		return true;
	}
	//Inserting in the middle of list
	else
	{
		previousNode->nextNodeAddress = newNode;
		newNode->nextNodeAddress = currentNode;

		itemsInList++;
		return true;
	}
}

bool LinkList::remove(const string nameToRemove)
{
	Node* currentNode = NULL;
	Node* previousNode = NULL;
	int itemLocation = 0;
	int indx = 0;

	//Make sure given string isnt empty and that string is in the list
	if (nameToRemove.empty() == true || find(nameToRemove) == 0)
	{
		return false;
	}

	currentNode = head;
	itemLocation = find(nameToRemove);

	//If we are deleting the last or only item in the list
	if (itemLocation == itemsInList)
	{
		while (currentNode->nextNodeAddress != NULL)
		{
			previousNode = currentNode;
			currentNode = currentNode->nextNodeAddress;
		}

		delete currentNode;

		//If it was the only item in the list
		if (previousNode == NULL)
		{
			head = NULL;
		}
		else
		{
			previousNode->nextNodeAddress = NULL;
		}

		itemsInList--;

		return true;
	}
	else
	{
		while (indx < (itemLocation - 1))
		{
			previousNode = currentNode;
			currentNode = currentNode->nextNodeAddress;
			indx++;
		}

		//If removing the first item
		if (previousNode == NULL)
		{
			head = currentNode->nextNodeAddress;
			delete currentNode;
			itemsInList--;
		}
		else
		{
			previousNode->nextNodeAddress = currentNode->nextNodeAddress;
			delete currentNode;
			itemsInList--;
		}
	}
	return true;
}

void LinkList::print() const
{
	Node* currentNode;

	if (head == NULL)
	{
		cout << "List is empty!" << endl;
		return;
	}

	currentNode = head;

	while (currentNode->nextNodeAddress != NULL)
	{
		cout << currentNode->name << ", ";

		currentNode = currentNode->nextNodeAddress;
	}
	cout << currentNode->name << endl;
}

int LinkList::count() const
{
	return itemsInList;
}

int LinkList::find(const string nameToFind) const
{
	Node* currentNode;
	int itemPosition = 1;

	//If the given string is empty or the list is empty, exit
	if (nameToFind.empty() == true || itemsInList == 0)
	{
		return 0;
	}

	currentNode = head;

	//Cycle through the list until the stings match or we hit the end of the list
	while (currentNode->name != nameToFind && currentNode->nextNodeAddress != NULL)
	{
		currentNode = currentNode->nextNodeAddress;
		itemPosition++;
	}

	if (currentNode->nextNodeAddress == NULL && currentNode->name != nameToFind)
	{
		return 0;
	}
	else
	{
		return itemPosition;
	}
}

bool LinkList::removeAll()
{
	Node* currentNode = NULL;
	Node* previousNode = NULL;

	if (head == NULL)
	{
		return false;
	}

	currentNode = head;

	head = NULL;

	while (currentNode->nextNodeAddress != NULL)
	{
		previousNode = currentNode;
		currentNode = currentNode->nextNodeAddress;

		delete previousNode;
	}

	delete currentNode;

	itemsInList = 0;

	return true;
}

LinkList* LinkList::duplicate()
{
	LinkList* newList;
	Node* currentOldNode = NULL;
	Node* currentNewNode = NULL;
	Node* nodeToInsert = NULL;

	currentOldNode = head;

	currentNewNode = new Node;

	currentNewNode->name = currentOldNode->name;

	newList->head = currentNewNode;

	for (int indx = 1; indx < itemsInList; indx++)
	{
		currentNewNode = currentNewNode->nextNodeAddress;

		//Create a new node
		nodeToInsert = new Node;

		//Copy the name over
		nodeToInsert->name = currentNewNode->name;

		//Point the previousNode to the newNode
		currentNewNode->nextNodeAddress = nodeToInsert;

		//Move our new node to the one we just added
		currentNewNode = currentNewNode->nextNodeAddress;
	}

	return newList;
}

bool LinkList::insertAfter(string nameToInsert, string nameInSlot)
{
	int indx = 0;
	int minStringSize = nameToInsert.length();

	if (nameToInsert.length() > nameInSlot.length())
	{
		minStringSize = nameInSlot.length();
	}

	//Keep moving through the two strings until two chars of the same indx != OR we have reached the end of our shortest string
	while (indx <= minStringSize && tolower(nameToInsert[indx]) == tolower(nameInSlot[indx]))
	{
		indx++;
	}

	//If the two strings are the same (ie: Bird == biRd)
	if (indx > minStringSize)
	{
		//It doesn't matter where we put the string, but return false to put it before
		return false;
	}

	if (tolower(nameToInsert[indx]) > tolower(nameInSlot[indx]))
	{
		return true;
	}
	else
	{
		return false;
	}

}
