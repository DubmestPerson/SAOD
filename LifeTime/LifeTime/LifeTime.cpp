// LifeTime.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Test.h"
#include "Child.h"
#include "Aggreagate.h"
#include "AggregateT.h"
#include <iostream>

Test gt;
int main()
{
    {
        printf("main: pre init\n");
        Test t;
        printf("main: post init\n");
    }
    printf("main: post delete\n");

    printf("\ncreating pt\n");
    Test* pt = new Test;
    delete pt;

    printf("\ncreating vector\n");
    Test* vt = new Test[10];
    delete[] vt;
    Test a(*pt);
    a.foo(a);
    printf("\ncreating child\n");
    Child c;
    printf("\ncreating aggregate\n");
    Aggregate agg(a);
    AggregateT<Test> at(a);

    AggregateT<Child> ac(c);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
