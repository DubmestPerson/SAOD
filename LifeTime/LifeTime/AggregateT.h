using namespace std;
template <typename T> class AggregateT
{
	T test;

public:
	AggregateT() {
		cout << "AggregateT object created" << endl;
	}

	AggregateT(T test) {
		this->test = test;
		cout << "AggregateT object created" << endl;
	}

	~AggregateT() {
		cout << "AggregateT object deleted" << endl;
	}
};
#pragma once
