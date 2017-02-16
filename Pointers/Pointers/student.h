#pragma once
#include <string>

class Student
{
public:
	Student();
	
	/*
	Input:
		cString -- no NULL
		float -- 0.0-4.0
	*/
	Student(float gpa, char* name);
	
	~Student();

	/*
	Input:
		cString -- no NULL
	*/
	void changeName(const char* newName);

	/*
	Input:
		string -- no empty string
			Out of bounds results in it being set to 0
	Returns:
		false -- if name is equal
		true -- if name is NOT equal
	*/
	bool isEqualTo(const char* name) const;

	void print() const;

private:
	float gpa;
	char* name;
};