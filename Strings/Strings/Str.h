#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>

class Str
{
	char* m_pszText;
public:
	Str() {m_pszText = new char[1]{ 0 };}

	Str(const char* p) {
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1]{ 0 };
	}

	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	const Str& operator = (const Str& s) //Константная ссылка на объект
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //Освобождаем текущие данные					//Дальше просто копирование
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText, strlen(s.m_pszText) + 1, s.m_pszText);
		return *this;
	}

	Str& operator +=(const char* sz) {
		int n = strlen(m_pszText);
		int m = strlen(sz);

		auto new_m_pszText =
			new char[n + m + 1];
		//for (int i = 0; i < m; i++)
		//	new_m_pszText[i] = sz[i];
		new_m_pszText[m+n] = 0;

		strcpy(new_m_pszText, this->m_pszText);
		
		strcat(new_m_pszText, sz);

		//for (int i = 0; i < n; i++)
		//	new_m_pszText[i] = m_pszText[i];
		//for (int i = 0; i < m; i++)
		//	new_m_pszText[i+n] = sz[i];

		delete[] m_pszText;
		m_pszText = new_m_pszText;
		return *this;
	}
	Str operator+(const char* sz) const {
		Str copy = *this;
		copy += sz;

		return copy;
	}
	operator const char* ()const { return m_pszText; }

	~Str() { delete[]m_pszText; }
};

