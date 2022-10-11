#pragma once
#include <iostream>
using namespace std;
class Test
{
	int test;

public:
	static int count;

	Test() {
		test = 10;
		count++;
		cout << "Object created and count is " <<count << endl;
	}

	Test(int test) {
		this->test = test;
		count++;
		cout << "Object created and count is " << count << endl;
	}

	Test(const Test& original) {
		test = original.test;
		count++;
		cout << "Object created and count is " << count << endl;
	}

	~Test() {
		count--;
		cout << "Object deleted and count is " << count << endl;
	}

	void foo(Test t) {
		cout << "foo is running" << endl;
	}
};
