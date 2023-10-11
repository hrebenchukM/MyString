#include<iostream>
#include "MyString.h"
#include <cassert> 
using namespace std;

int main()
{
	MyString s4 = MyString("Test");
	MyString s5 = MyString("Test");
	MyString s6= MyString("Test by Mary Hrebenchuk");

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
	s.MyDelChr('i');
	assert(strcmp(s.GetStr(), "Ths s test") == 0);// ���������, ��� ������ 'e' ������ �����

	// ��������� �����
	
	assert(s5.MyStrCmp(s4) == 0); // ��������� 0, ��� ��� ������ �����
	assert(s5.MyStrCmp(s6) < 0); // ��������� -1, ��� ��� ������ ������ ������ ������
	assert(s6.MyStrCmp(s4) > 0); // ��������� 1, ��� ��� ������ ������ ������ ������



	cout << endl<<"All tests passed!" << endl;





}