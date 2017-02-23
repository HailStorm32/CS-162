#include <iostream>
#include "student.h"

using namespace std;

Student::Student()
{
	studentGpa = 0;
	studentName = NULL;
}

Student::Student(float gpa, char * name)
{
	//Only set the gpa to the given array if its in bounds
	if (gpa >= 0 || gpa <= 4.9)
	{
		studentGpa = gpa;
	}
	else
	{
		studentGpa = 0;
	}

	//Allocate enough space for the name in the heap, get the address and then copy the contents of student name
	studentName = new char[strlen(name) + 1];
	strcpy(studentName, name);
}

Student::~Student()
{
	if (studentName != NULL)
	{
		delete[] studentName;
	}
}

void Student::changeName(const char * newName)
{
	//Delete the old pointer
	delete[] studentName;

	//Allocate enough space for the name in the heap, get the address and then copy the contents of student name
	studentName = new char[strlen(newName) + 1];
	strcpy(studentName, newName);
}

bool Student::isEqualTo(const char * name) const
{
	//Get the lengths of the name we are looking for and the current name
	int lenOfName2Find = strlen(name);
	int lenOFName = strlen(studentName);

	//If the lengths arent equal, we know for a fact that the names arent equal
	if (lenOfName2Find != lenOFName)
	{
		return false;
	}

	//Since the lengths are equal, compare char by char
	for (int indx = 0; indx < lenOfName2Find; indx++)
	{
		//If we get a char that doesn't match, return false
		if (studentName[indx] != name[indx])
		{
			return false;
		}
	}
	return true;
}

void Student::print() const
{
	cout << studentName << " (" << studentGpa << ")";
}
