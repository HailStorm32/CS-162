#pragma once
using namespace std;

const int MAX_ITEMS = 10;


class List
{
public:
	List();

	/*
	Input:
		string -- no empty string
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool insert(string text);

	/*
	Input:
		string -- no empty string
	Returns:
		false -- if failed
		true -- if succeeded
	*/
	bool remove(string text);

	/*
	Input:
		string -- no empty string
	Returns:
		-1 -- if failed
		# >= 0 -- if succeeded (and index where word was found)
	*/
	int inList(string text) const;

	/*
	Input:
		NONE
	Returns:
		false -- if NOT empty
		true -- if empty
	*/
	bool isEmpty() const;

	/*
	Input:
		NONE
	Returns:
		false -- if NOT full
		true -- if full
	*/
	bool isFull() const;

	/*
	Input:
		NONE
	Returns:
		NONE
	*/
	void print();

private:
	string items[MAX_ITEMS];
	int totalItems;

	/*
	Input:
		NONE
	Returns:
		-1 -- if failed
		# >= 0 -- if succeeded (and index where the first slot was found)
	*/
	int findEmpty() const;
};