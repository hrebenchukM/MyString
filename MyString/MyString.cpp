#include "MyString.h"
#include<string.h>
#include<iostream>
using namespace std;


MyString::MyString()
{
	str = new char[80];
	size = 0;
}

MyString::MyString(int size)
{

	str = new char[size];
	size = 0;

}

MyString::MyString(const MyString& obj) {
	str = new char[obj.size + 1];
	strcpy_s(str, obj.size + 1, obj.str);
	size = obj.size;
}


MyString::MyString(const char* s)
{
	size = strlen(s);//Чтоб не писать постоянно и не считать постоянно количество символов
	str = new char[size + 1];
	strcpy_s(str, size + 1, s);
}

MyString::~MyString()
{
	delete[]str;
}

void MyString::Print()
{
	cout << str ;
}

void MyString::Input()
{
	char buff[100];
	cout << "Enter string: ";
	cin >> buff;
	size = strlen(buff);
	if (str != nullptr)
	{
		cout << "Delete -> " << str << "... \n";
		delete[] str;
	}
	str = new char[size + 1];
	strcpy_s(str,size + 1, buff);
}

void MyString::MyStrcpy(MyString& obj)
{
	str = new char[obj.size + 1];
	strcpy_s(str, obj.size + 1, obj.str);
	size = obj.size;
}

bool MyString::MyStrStr(const char* s)
{
	return strstr(str,s) !=nullptr;
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < size; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	return size;
}

void MyString::MyStrCat(MyString& b)
{
	char* newstr = new char[size + b.size + 1];
	for (int i = 0; i < size; i++) {
		newstr[i] = str[i];
	}
	for (int i = 0; i < b.size; i++) {
		newstr[size + i] = b.str[i];
	}
	newstr[size + b.size] = 0;
	delete[] str;
	str = newstr;
	size = size + b.size;

//	strcat_s(str, size, b.str);
}

MyString MyString::operator+(MyString& b) {
	MyString newstr(*this);
	newstr.MyStrCat(b);
	return newstr;
}

char* MyString::GetStr()
{
	return str;
}

int MyString::GetSize()
{
	return size;
}



