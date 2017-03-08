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

	list1.insert("Apple");

	/*if (!list1.insert("Jack"))
	{
		cout << "FALSE" << endl;
	}*/

	list1.insert("Jamie");
	
	list1.insert("Cat");

	list1.insert("applez");

	list1.insert("Buy");

	list1.insert("appLE");

	list1.insert("Great");

	list1.insert("~");

	list1.insert("Car");
	
	list1.insert("Apple");

	list1.print();

	cout << list1.count();

	//Allow console to stay open
	cin.get();
	cin.ignore();

}