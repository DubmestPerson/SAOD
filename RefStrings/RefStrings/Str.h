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
	Str() { m_pStr = new _str; }		//���� �� �����, �� �������

	Str(const char* p) {		// ����� ������
		m_pStr = new _str(p);
	}

	Str(const Str& s)
	{
		m_pStr = s.m_pStr; 	// ��������� �� ��� �� ������
		m_pStr->AddRef(); 	// ��������, ��� ���������
	}

	~Str() {
		m_pStr->Release(); 	// �� ���������� ������!
	}				// ��������� ������� ������!

	int len() const {
		return strlen(m_pStr->m_pszData);
	}

	// ������� ��� ������ ��������� � ������
	// + ����� �������, � ������� ���������� ���������
public: int rFind(const char* t, int k) const
	{
	cout << t << endl;
		int i, j; // �������� ��� ������
		int lenThis, lenT; // ����� �����
		int displacement = 0;

		//������� ������� ������ ��������� � ��������
		for (lenThis = 0; m_pStr->m_pszData[lenThis]; lenThis++);
		for (lenT = 0; t[lenT]; lenT++);

		for (i = lenThis; i <= lenThis && displacement < k; i--) // ���� ���� ����������� ������
		{
			cout << i << "  " << lenThis <<" i - iter" << endl;
			displacement++;
			cout << t[lenThis-i] << "    " << m_pStr->m_pszData[0] << "Pri i =" << i << endl;
			for (j = 0; t[i + j] == m_pStr->m_pszData[j] && j < lenT; j++) {
				cout << "kall" << endl;
				cout << t[i + j] << "    " << m_pStr->m_pszData[j] << "Pri i =" << i << endl;
			}; // ��������� ���������� �����������
			// ���� ����������� ��������� �� ����� ��������
			// ������ �� ������� ����� ������, ������ ���������� ����������
			cout << j << " -j- " << j - lenT << endl;
			if (j - lenT == 1) {
				
				if(i < lenT) return i;
			}
		}
		//����� ������ -1 ��� ��������� ���������� ���������
		return -1;
	}

	//1.	������������ ��������� ����� int rfind(const char* t, int off) const, ������� ���� ��������� ��������� ��������� t � �������� ������, �� �������� off.
	//	�.�.��������� ���������� �� ����� ���������� ����� off.
	//	���� ��������� ���, �� ����� ���������� - 1, ���� ����, �� ������ ���������� ��������� �� off �� ������ �������� ������.

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


	//������������ �������� ���������!
	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef(); // ����� �������?!
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	///��������� +=, []
	Str& operator+=(const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) { // ���������� ������ �� �������!
			_str* pstrTmp = new _str; // ����� ������
			delete[] pstrTmp->m_pszData;

			pstrTmp->m_pszData = new char[length + 1];
			strncpy(pstrTmp->m_pszData, m_pStr->m_pszData, length + 1);
			strncat(pstrTmp->m_pszData, s.m_pStr->m_pszData, length + 1);

			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	// �������� �������������� Str � ���� const char*
	operator const char* ()const {
		/*
		int length = strlen(m_pStr->m_pszData) + 1;
		char* m_copy = new char[length];
		strcpy_s(m_copy, length, m_pStr->m_pszData);*/
		return m_pStr->m_pszData;
	}
};


