#pragma once
#include <iostream>
using namespace std;

class Test
{
public:
	int Val;
	Test()
	{
		Val = 0;
		cout << "Constructor worked" << endl;
	}
	~Test()
	{
		cout << "Destructor worked" << endl;
	}
};