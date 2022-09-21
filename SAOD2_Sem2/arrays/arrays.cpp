

#include <iostream>
using namespace std;


//void rotate(int a[], int n) {
//	int x = a[0];
//	cout <<"rot"<<endl;
//	for (int i = 1; i <= n / 2; i++) {
//		a[i-1] = a[n - i];
//		a[n - i] = x;
//		x = a[i];
//	}
//}
void rotate(int a[], int n) {
	int x = a[0];
	for (int i = 1; i < n; i++)
		a[i - 1] = a[i];
	a[n - 1] = x;
}

void SecondRotate(int a[], int n, bool clockwise = false) {
	if (clockwise) {
		int x = a[0];
		for (int i = 1; i < n; i++)
			a[i - 1] = a[i];
		a[n - 1] = x;
	}
	else {
		int x = a[n - 1];
		for (int i = n - 1; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = x;
	}
}

int main()
{
	//5
	int a[5]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << endl;

	for (int* p = a; p - a < 5; p++) {
		cout << *p << ' ';
	}
	cout << endl;

	rotate(a, 5);
	for (int* p = a; p - a < 5; p++)
		cout << *p << ' ';
	cout << endl;

	SecondRotate(a, 5, true);
	for (int* p = a; p - a < 5; p++)
		cout << *p << ' ';
	cout << endl;

	SecondRotate(a, 5, false);
	for (int* p = a; p - a < 5; p++)
		cout << *p << ' ';
	cout << endl;

	return 0;
}

