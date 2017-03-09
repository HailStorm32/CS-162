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
	LinkList* list1 = new LinkList;
	LinkList* list2;

	list1->insert("Bill");
	list1->print();
	list1->insert("Adam");
	list1->print();
	list1->insert("Zorro");
	list1->print();
	list1->insert("Kelly");
	list1->print();
	list1->insert("Chris");
	list1->print();

	cout << list1->count() << endl;

	list2 = list1->duplicate();

	cout << endl;

	list1->remove("Zorro");
	list1->print();
	list1->remove("Charlie");
	list1->print();
	list1->remove("Becky");
	list1->print();
	list1->remove("Adam");
	list1->print();
	list1->remove("Kelly");
	list1->print();

	cout << endl;

	list2->insert("Sam");
	cout << list2->count() << endl;

	cout << endl;

	string namesToFind[4] = { "George", "Adam", "Kelly", "Zorro" };
	int nameLocation = 0;

	for (int indx = 0; indx < 4; indx++)
	{
		nameLocation = list2->find(namesToFind[indx]);

		if (nameLocation == 0)
		{
			cout << "Position of " << namesToFind[indx] << " is: DOES NOT EXIST!" << endl;
		}
		else
		{
			cout << "Position of " << namesToFind[indx] << " is: " << nameLocation << endl;
		}
	}

	delete list2;

	cout << "\nDone!" << endl;

	delete list1;

	//Allow console to stay open
	cin.get();
	cin.ignore();

}