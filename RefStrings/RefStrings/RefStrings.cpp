// RefStrings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Str.h"

int main()
{
    Str st;
    st = "Hello";
    cout << "st = " << st << endl;

    Str st1 = "worldworldworld!";
    st += st1;
    cout << "st = st + st1 = " << st << endl;

    cout << "st[4] = " << st[4] << endl;
    Str st3 = "wo";

    cout << st.rFind(st3, 7) << endl;



}

