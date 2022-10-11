#pragma once
#include <iostream>
#include "Test.h"
using namespace std;

class Child : public Test
{
	int childTest;

public:

	Child() {
		cout << "Child object created" << endl;
		count++;
	}

	Child(int test) {
		this->childTest = test;
		cout << "Child object created" << endl;
		count++;
	}

	~Child() {
		cout << "Child object deleted" << endl;
		count--;
	}
};
