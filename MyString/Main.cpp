#include<iostream>
#include "MyString.h"
#include <cassert> 
using namespace std;

int main()
{
	MyString s = MyString("This is test");
	s.Print();
	cout << endl;

	MyString s2 = MyString(".Very tasty...");
	s2.Print();
	cout << endl;

    // ����������� �����
	MyString s3;// = s;
	s3.MyStrcpy(s);
	s3.Print();

	// ����� ��������� � ������
	//�������������� ��� ������ ����� �������� ���������
	assert(s.MyStrStr("test"));//�������� ������ ���� true
	assert(!s.MyStrStr("test2"));//!�������� ������ ���� false


	// ����� ������� � ������(������ ���������� �������, ���� -1)
	assert(8 == s.MyChr('t'));//�������� ������ ���� true
	assert(-1 == s.MyChr('b'));//!�������� ������ ���� false

	// ���������� ����� ������
	assert(12 == s.MyStrLen());



	// ����������� ����� � �������������� ���������� ��������� +
	MyString result = s + s2;
	assert(strcmp(result.GetStr(), "This is test.Very tasty...") == 0); // ���������, ��� ������ ���������� �����

	// �������� ������� 'e' �� ������
	s.MyDelChr('e');
	assert(strcmp(s.GetStr(), "This is tst.Vry tasty...") == 0);// ���������, ��� ������ 'e' ������ �����

	// ��������� �����
	MyString s4 = MyString("This is test");
	assert(s.MyStrCmp(s4) == 0); // ��������� 0, ��� ��� ������ �����
	assert(s.MyStrCmp(s2) < 0); // ��������� -1, ��� ��� ������ ������ ������ ������
	assert(s2.MyStrCmp(s4) > 0); // ��������� 1, ��� ��� ������ ������ ������ ������



	if (s == s2) {
		cout << "Strings ==." << endl;
	}
	else if (s != s2) {
		cout << "Strings not ==." << endl;
	}
	if (s == s4) {
		cout << "Strings ==." << endl;
	}
	else if (s != s4) {
		cout << "Strings not ==." << endl;
	}




	cout << "All tests passed!" << endl;





}