#pragma once
#include <iostream>
#include "Test.h"
using namespace std;

class Aggregate
{
	Test aggregate;

public:

	Aggregate(Test test) {
		this->aggregate = test;
		cout << "Aggregate object created" << endl;
	}

	~Aggregate() {
		cout << "Aggregate object deleted" << endl;
	}
};