#pragma once
using namespace std;

const int MAX_ITEMS = 3;


class List
{
public:
	List();

	bool insert(string text);
	bool remove(string text);

	bool inList(string text) const;
	bool isEmpty() const;
	bool isFull() const;
	void print();

private:
	string listContents[MAX_ITEMS];
	int totalItems;
};