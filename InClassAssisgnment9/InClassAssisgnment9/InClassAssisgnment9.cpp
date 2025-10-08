// InClassAssisgnment9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyList.h"

using namespace std;

int main()
{
	int tempInt;
	MyList list;
	for (tempInt != 0;;) {
		cout << "Input a number: ";
		cin >> tempInt;
		cout << endl;
		if (tempInt != 0) {
			list.push_back(tempInt);
		}
	}	
	cout << endl << "Size: " << list.size() << endl;
	list.DisplayAndRemoveAll();
	cout << endl << "Size: " << list.size() << endl;
}











