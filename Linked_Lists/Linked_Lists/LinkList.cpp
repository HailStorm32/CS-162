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
}

LinkList::~LinkList()
{
}

bool LinkList::insert(const string nameToInsert)
{
	if (nameToInsert.empty() == true) //Add check to see if it finds duplicate
	{
		return false;
	}

	//Create new node
	Node* newNode = new Node;
	newNode->name = nameToInsert;
	newNode->nextNode = NULL;
	
	//If list is empty, 
	if (head == NULL)
	{
		head == newNode;
		return true;
	}
	
	return true;
}

bool LinkList::remove(const string nameToRemove)
{
	return false;
}

void LinkList::print() const
{
}

int LinkList::count() const
{
	return 0;
}

int LinkList::find(const string nameToFind) const
{
	return 0;
}

bool LinkList::removeAll()
{
	return false;
}

LinkList LinkList::duplicate(LinkList listToCopy)
{
	return LinkList();
}
