/*
Program: LinkedListTest.cpp
Author: Demetri Van Sickle
Date: 3/2/17
Description: Contains the code to test the linked list
*/
#include <iostream>
#include "LinkList.h"

using namespace std;

void main()
{
	int num = -1;

	LinkList list1;

	list1.insert("Jack");

	if (!list1.insert("Jack"))
	{
		cout << "FALSE" << endl;
	}

	list1.insert("Jamie");
	
	list1.insert("Bob");

	num = list1.find("bob");

}