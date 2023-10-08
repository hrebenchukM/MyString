#include<iostream>
#include "MyString.h"
#include <cassert> 
using namespace std;

int main()
{
	MyString s = MyString("This is test");
	MyString s2 = MyString(".Very tasty...");
	s.Print();
	//s.Input();
	//s.Print();

	//MyString s2;// = s;
	//s2.MyStrcpy(s);
	//s2.Print()
	
	//�������������� ��� ������ ����� �������� ���������
	assert(s.MyStrStr("test"));//�������� ������ ���� true
	assert(!s.MyStrStr("test2"));//!�������� ������ ���� false
	assert(8 == s.MyChr('t'));//�������� ������ ���� true
	assert(-1 == s.MyChr('b'));//!�������� ������ ���� false
	assert(12 == s.MyStrLen());

	MyString sconcat(s);
	sconcat.MyStrCat(s2);
	cout << endl << "sconcat=";
	sconcat.Print();
	assert(0 == strcmp("This is test.Very tasty...", sconcat.GetStr()));

	MyString s3 = s + s2;
	cout << endl << "s3=";
	s3.Print();
	assert(0 == strcmp("This is test.Very tasty...", s3.GetStr()));

}