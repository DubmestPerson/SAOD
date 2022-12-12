#include <iostream>
#include <memory>
#include "Test.h"

using namespace std;

int main()
{
    //shared_ptr<Test> sp(new Test[3]);
    //shared_ptr<Test[]> sp(new Test[3]);
    //shared_ptr<Test> sp(new Test[3], default_delete<Test[]>());
    //Test* t = sp.get();
    //for (int i = 0; i < 3;i++)
    //{
    //    cout << t[i].Val << "\t";
    //    t[i].Val = i;
    //    cout << t[i].Val << endl;
    //}

    unique_ptr<Test[]> p(new Test[3]);
    cout << p[1].Val << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << p[i].Val << "\t";
        p[i].Val = i;
        cout << p[i].Val << endl;
    }
    cout << "---------" << endl;
    p.reset(new Test[1]);
    cout << "---------" << endl;
}
