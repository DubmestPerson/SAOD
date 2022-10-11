// Strings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include "Str.h"
using namespace std;
void Test(Str s) {}
int main()
{
    Str s = "asd";
    //s = "12345";
    cout << s << endl;

    cout << "strlen: " << strlen(s) << endl;

    Test(s);

    cout << s << endl;
    
    {
        Str t;
        t = s = t;
    }
    cout << s << endl;
    cout << "strlen: " << strlen(s) << endl;
    {
        s += " keki4";
        cout << s << endl;
    }
    {
        Str a = "a";
        Str b = "b";
        Str ab = a + b;
        cout << ab << endl;
    }

    return 0;
}

