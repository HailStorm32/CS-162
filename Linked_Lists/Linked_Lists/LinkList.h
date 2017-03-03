/*
Program: LinkList.h
Author: Demetri Van Sickle
Date: 3/2/17
Description: Contains LinkList definition code
*/
#pragma once
#include <string>

using namespace std;

class LinkList
{
public:
	LinkList();
	
	~LinkList();

	/*
	Input:
		string -- no duplicates or empty strings
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool insert(const string nameToInsert);

	/*
	Input:
		string -- no empty strings
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool remove(const string nameToRemove);

	void print() const;

	/*
	Returns:
		0-n -- items in the list
	*/
	int count() const;

	/*
	Input:
		string -- no empty strings
	Returns:
		1-n -- position in the list
		0 -- if sting is not found
	*/
	int find(const string nameToFind) const;
	
	/*
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool removeAll();

	/*
	Input:
		LinkList -- no empty list
	Returns:
		Pointer to the copied LinkList
	*/
	LinkList duplicate(LinkList listToCopy);

private:
	struct Node
	{
		string name;
		Node* nextNode;
	};

	int itemsInList;
	Node* head;
};