#pragma once

#include <string>
#include "student.h"

const int MAX_STUDENTS = 10;

class StudentList
{
public:
	StudentList();
	~StudentList();

	/*
	Input:
		Student class member
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool insert(Student* student);

	/*
	Returns:
		false -- if list is NOT empty
		true -- if list is empty
	*/
	bool isEmpty();

	/*
	Returns:
		false -- if list is NOT full
		true -- if list is full
	*/
	bool isFull();

	/*
	Input:
		cString -- no NULL
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool remove(char* name);


	void print() const;


private:
	int itemsInList;

	Student * students[MAX_STUDENTS];

	/*
	Returns:
		-1 -- if list is full
		index of empty slot -- if found
	*/
	int findEmpty();

	/*
	Returns:
		-1 -- if list is empty
		index of where item was found -- if found
	*/
	int findInList(char * name);
};
