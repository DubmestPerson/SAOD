#pragma once
#include <string.h> 
#include "_str.h"
#include <iostream>
#include <stdexcept> 
#include <stdio.h>
using namespace std;
class Str {

	_str* m_pStr;

public:
	Str() { m_pStr = new _str; }		//если не копия, то создаем

	Str(const char* p) {		// новый ресурс
		m_pStr = new _str(p);
	}

	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ссылаемся на тот же ресурс
		m_pStr->AddRef(); 	// отмечаем, что сослались
	}

	~Str() {
		m_pStr->Release(); 	// Не уничтожаем ресурс!
	}				// Уменьшаем счетчик ссылок!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}

	// Функция для поиска подстроки в строке
	// + поиск позиции, с которой начинается подстрока
public: int rFind(const char* t, int k) const
	{
	cout << t << endl;
		int i, j; // Счетчики для циклов
		int lenThis, lenT; // Длины строк
		int displacement = 0;

		//Находим размеры строки исходника и искомого
		for (lenThis = 0; m_pStr->m_pszData[lenThis]; lenThis++);
		for (lenT = 0; t[lenT]; lenT++);

		for (i = lenThis; i <= lenThis && displacement < k; i--) // Пока есть возможность поиска
		{
			cout << i << "  " << lenThis <<" i - iter" << endl;
			displacement++;
			cout << t[lenThis-i] << "    " << m_pStr->m_pszData[0] << "Pri i =" << i << endl;
			for (j = 0; t[i + j] == m_pStr->m_pszData[j] && j < lenT; j++) {
				cout << "kall" << endl;
				cout << t[i + j] << "    " << m_pStr->m_pszData[j] << "Pri i =" << i << endl;
			}; // Проверяем совпадение посимвольно
			// Если посимвольно совпадает по длине искомого
			// Вернем из функции номер ячейки, откуда начинается совпадение
			cout << j << " -j- " << j - lenT << endl;
			if (j - lenT == 1) {
				
				if(i < lenT) return i;
			}
		}
		//Иначе вернем -1 как результат отсутствия подстроки
		return -1;
	}

	//1.	Разработайте публичный метод int rfind(const char* t, int off) const, который ищет последнее вхождение подстроки t в исходную строку, до смещения off.
	//	Т.е.найденное совпадение не может начинаться после off.
	//	Если вхождения нет, то метод возвращает - 1, если есть, то индекс последнего вхождения до off от начала исходной строки.

//public: 
//	int rFind(const char* t, int off) const {
//		for (int i = strlen(m_pStr->m_pszData) - strlen(t); strlen(m_pStr->m_pszData) - i < off; i--) {
//			bool flag = 0;
//			for (int j = 0; j < strlen(t); j++)
//			{
//				if (m_pStr->m_pszData[i + j] == t[j]) continue;
//				flag = 1;
//				break;
//			}
//			if (!flag) return i;
//		}
//		return -1;
//	}


	//Присваивание образует выражение!
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // Важен порядок?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	///Операторы +=, []
	Str& operator+=(const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) { // добавление ничего не изменит!
			_str* pstrTmp = new _str; // Новый ресурс
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strncpy(pstrTmp->m_pszData, m_pStr->m_pszData, length + 1);
			strncat(pstrTmp->m_pszData, s.m_pStr->m_pszData, length + 1);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	// оператор преобразования Str к типу const char*
	operator const char* ()const {
		/*
		int length = strlen(m_pStr->m_pszData) + 1;
		char* m_copy = new char[length];
		strcpy_s(m_copy, length, m_pStr->m_pszData);*/
		return m_pStr->m_pszData;
	}
};


