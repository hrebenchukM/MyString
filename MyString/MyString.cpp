#include "MyString.h"
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

static int objectCount;
MyString::MyString()
{
	str = new char[80];
	size = 0;
	objectCount++;
}


MyString::MyString(char c)
{
	size = 1;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
	objectCount++;
}


MyString::MyString(int size)
{
	this->size = 0;
	str = new char[size];
	objectCount++;
	

}

MyString::MyString(const MyString& obj) {
	str = new char[obj.size + 1];
	strcpy_s(str, obj.size + 1, obj.str);
	size = obj.size;
	objectCount++;
}


MyString::MyString(const char* s)
{
	size = strlen(s);//Чтоб не писать постоянно и не считать постоянно количество символов
	str = new char[size + 1];
	strcpy_s(str, size + 1, s);
	objectCount++;
}

MyString::~MyString()
{
	delete[]str;
	objectCount--;
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

bool MyString::MyStrStr(const char* sub)
{
	int substrSize=0;
	for (substrSize; sub[substrSize] != '\0';) {
		substrSize++;
	}

	for (int i = 0; i <= size - substrSize; ++i) {
		bool founded = true;
		for (int j = 0; j < substrSize; ++j) {
			if (str[i + j] != sub[j]) {
				founded = false;
				break;
			}
		}
		if (founded) {
			return true;
		}
	}
	return false;
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
}

void MyString::MyDelChr(char c) {
	int newSize = 0;
	for (int i = 0; i < size; ++i) {
		if (str[i] != c) {
			++newSize;
		}
	}

	char* newStr = new char[newSize+1 ];
	int newIndex = 0;
	for (int i = 0; i < size; ++i) {
		if (str[i] != c) {
			newStr[newIndex++] = str[i];
		}
	}
	newStr[newIndex] = '\0';

	delete[] str;
	str = newStr;
	size = newSize;//Like (size - count of c)
}
	



int MyString::MyStrCmp(MyString& b)
{
		int i = 0;
		while (str[i] == b.str[i] && str[i] != '\0' && b.str[i] != '\0') {//сравнивает символы в строках до тех пор, пока они совпадают и не достигнут конца одной из строк. 
			i++;
		}

		if (str[i] < b.str[i]) {
			return -1;
		}
		else if (str[i] > b.str[i]) {
			return 1;
		}
		else {
			return 0;
		}
}


void MyString::SetSize(int n)
{
	if (n >= 0)
	{
		size = n;
	}
	else
	{
		size = 0;
	}
}
void MyString::SetStr(const char* n)
{
	
	if (str != nullptr)
	{
		delete[] str;
	}
	size = strlen(n);
	str = new char[size + 1];
	strcpy_s(str, size + 1, n);
}

char* MyString::GetStr()
{
	return str;
}

int MyString::GetSize()
{
	return size;
}

int MyString::GetTotalObjects()
{
		return objectCount;
}




MyString MyString::operator+(MyString& b)
{
	MyString newstr(*this);
	newstr.MyStrCat(b);
	return newstr;
}

//MyString& MyString::operator++()
//{
//		MyString temp("X");
//		MyStrCat(temp);
//		return *this;
//	
//}


MyString& MyString::operator+=( MyString& b)
{
	MyStrCat(b); 
	return *this;
}




char& MyString::operator[](const int index) {
	if (index < 0)
	{
		return str[0];
	}
	else if (index >size)
	{
		return str[size - 1];
	}
	else
	{
		return str[index];
	}

}


void MyString ::operator()() 
{
	Input();
}


MyString& MyString::operator=(const MyString& b)
{
	if (this != &b) // 1 a=a
	{
		delete[] str;// 2 a=b
		size = b.size;
		str = new char[size + 1]; //3

		strcpy_s(str, size + 1, b.str);//3
	}
	
	return *this;//4
}

MyString::MyString(MyString&& b)
{
	str = b.str;
	b.str = nullptr;
	size = b.size;
	b.size = 0;
	cout << "Move constructor" << endl;
	objectCount++;
}

MyString& MyString::operator=(MyString&& obj)
{
	if ( this == &obj)
	{
		return *this;
		
	}
	delete[] str;
	size = obj.size;
	obj.size = 0;
	str = obj.str;
	obj.str = nullptr;

	return *this;
}
//
//MyString MyString::operator+(char c)
//{
//	MyString newstr(*this);
//	MyString s2(c);
//	newstr.MyStrCat(s2);
//	return newstr;
//}
//
//
//MyString MyString::operator+(int b)
//{
//	int newSize = size + b;
//	MyString rez(newSize+1);
//
//	for (int i = 0; i < size; i++)
//	{
//		rez.str[i] = str[i];
//	}
//
//	for (int i = 0; i <b; i++)
//	{
//		rez.str[size + i] = '0';
//
//	}
//	rez.str[newSize] = '\0';
//	return rez;
//}


//
//bool MyString::operator==(const MyString& obj)  
//{
//	return MyStrStr(obj.str);
//}
//
//bool MyString::operator!=(const MyString& obj) {
//	return !MyStrStr(obj.str);
//}
//