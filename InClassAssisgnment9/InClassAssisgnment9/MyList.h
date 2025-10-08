#pragma once

#include <list>
using namespace std;

class MyList : public list<int> {
public:
	void DisplayAndRemoveAll();
};