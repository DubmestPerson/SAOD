// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PF.h"
#include <bitset>
#include <algorithm>
#include <string>

typedef unsigned char byte;

string bin(unsigned char b)
{
    int dec = (int)b;
    string bin;

    for (int j = 0; j < 8; j++)
    {
        if (dec % 2 == 1) bin += '1';
        if (dec % 2 == 0) bin += '0';
        dec /= 2;
    }
    reverse(bin.begin(), bin.end());

    return bin;
}

int main()
{
	// Распознаваемый код вируса HLLP.Light.4859 (один из Trojan)		
	byte vCode[] = {0x88, 0x42, 0xE0, 0x46, 0xEB, 0x27, 0x00, 0xED, 0x3F, 0x8B, 0xCE, 0xE3, 0x12, 0x8D, 0x7E, 0xE0};

    char* t = new char[sizeof(vCode) * 8 + 1]{ 0 };
	
    string s;
    for (byte* p = vCode; p - vCode < sizeof(vCode); p++)
        s += bin(*p);
    copy(s.begin(), s.end(), t);
    t[sizeof(vCode) * 8] = '\0';

    //Тест
    /*string s = "101001110101";
    char* t = new char[s.length() + 1] { 0 };
    copy(s.begin(), s.end(), t);
    t[s.length()] = '\0';*/

    /*cout << t << endl;
    cout << strlen(t) << endl;*/

    int N = 1024;
    /*const byte* p1 = (byte*)main;*/
    const byte* p1 = (byte*)vCode;
    /*const byte* p1 = (byte*)bin;*/
    char* T = new char[1024 * 8 + 1]{};
    string s1;
    byte b;
    for (int i = 0; i < N; i++)
    {
        b = *p1++;
        s1 += bin(b);
    }
    copy(s1.begin(), s1.end(), T);
    T[1024 * 8] = '\0';

    /*cout << T << endl;
    cout << strlen(T) << endl;*/

    char* W = new char[strlen(t) + 1 + 1024 * 8 + 1];
    strcpy_s(W, strlen(t) + 1, t);
    W[strlen(t)] = '&';
    strcpy_s(W + strlen(t) + 1, 1024 * 8 + 1, T);
    W[strlen(t) + 1 + 1024 * 8] = '\0';

    cout << W << endl;
    /*cout << strlen(W) << endl;*/

    PF PrefixFunction;
    PrefixFunction.Init(W);
    int len = PrefixFunction;

    int col = 0;
    for (int i = 2 * strlen(t); i < len; i++)
    {
        if (PrefixFunction[i] == strlen(t))
        {
            cout << "Position: " << i - 2 * strlen(t) << endl;
            col++;
        }
    }
    if (col == 0)
        cout << "Code is healthy";

    delete[] t;
    delete[] T;
    delete[] W;
}

