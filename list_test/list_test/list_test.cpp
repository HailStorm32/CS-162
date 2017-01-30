#include <iostream>
#include "list.h"
#include <string>

using namespace std;

void main()
{
	List list1;

	if (list1.insert("Robot") == false)
	{
		cout << "Was FALSE!" << endl;
	}
	else
	{
		cout << "Was TRUE!" << endl;
	}




}