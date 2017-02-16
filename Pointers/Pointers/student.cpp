#include <iostream>
#include "student.h"

Student::Student()
{
	gpa = 0;
	name = NULL;
}

Student::Student(float gpa, char * name)
{
	if (gpa < 0 || gpa > 4.9)
	{
		this->gpa = gpa;
	}

	this-> name = new char[strlen(name)];

	

}

Student::~Student()
{
}

void Student::changeName(const char * newName)
{
}

bool Student::isEqualTo(const char * name) const
{
	return false;
}

void Student::print() const
{
}
