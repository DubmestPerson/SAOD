

#include <iostream>
#include <complex.h>
#include <cmath>
using namespace std;

int main()
{
    Complex c;
    cout << c;
    Complex a(1, 2), b = 3;
    ((cout << a) << ", ") << b << endl;
    Complex n[5];
    //for (int i = 0; i < 5; i++)
    //{
    //    cout << n[i] << " ";
    //}
    Complex v[4] { 1,2, Complex(2,3) };
    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
    Complex *pc;
    pc = new Complex(1,2);
    cout << *pc<< '\n';
    cout << pc->Re<<'\n';
    cout << pc->Im<< '\n';
    delete pc;
    pc = new Complex[3];
    cout << pc[2].Re;
    delete[] pc;
    


}

