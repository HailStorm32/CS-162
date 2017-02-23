#include <iostream>
#include "studentList.h"

using namespace std;

StudentList::StudentList()
{
	itemsInList = 0;

	//Set all indexes of the Student array to NULL
	for (int indx = 0; indx < MAX_STUDENTS; indx++)
	{
		students[indx] = NULL;
	}
}

StudentList::~StudentList()
{
	//Find indexes that are NOT NULL and delete them
	for (int indx = 0; indx < MAX_STUDENTS; indx++)
	{
		if (students[indx] != NULL)
		{
			delete students[indx];
		}
	}
}

bool StudentList::insert(Student * student)
{
	int emptySlot = findEmpty();

	//Dont continue if the array is full
	if (emptySlot < 0)
	{
		return false;
	}

	//Put the address of the given student data into the list
	students[emptySlot] = student;

	itemsInList++;

	return true;
}

bool StudentList::isEmpty()
{
	if (itemsInList == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StudentList::isFull()
{
	if (itemsInList == MAX_STUDENTS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StudentList::remove(char * name)
{
	int itemPosition = findInList(name);

	//Dont continue if the array is empty
	if (itemPosition < 0)
	{
		return false;
	}

	delete students[itemPosition];
	
	students[itemPosition] = NULL;
	
	itemsInList--;

	return true;
}

void StudentList::print() const
{
	//Cycle through the indexes of the array
	for (int indx = 0; indx < MAX_STUDENTS; indx++)
	{
		//only print non-NULL indexes
		if (students[indx] != NULL)
		{
			students[indx]->print();
			cout << ", ";
		}
	}
	cout << endl;
}

int StudentList::findEmpty()
{
	if (isFull())
	{
		return -1;
	}

	//Cycle through the indexes of the array and return the index of the first empty array
	for (int indx = 0; indx < MAX_STUDENTS; indx++)
	{
		if (students[indx] == NULL)
		{
			return indx;
		}
	}
}

int StudentList::findInList(char * name)
{
	for (int indx = 0; indx < MAX_STUDENTS; indx++)
	{
		if (students[indx] != NULL && students[indx]->isEqualTo(name))
		{
			return indx;
		}
	}

	return -1;
}
