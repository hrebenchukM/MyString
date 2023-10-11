#include "MyString.h"
#include<string.h>
#include<iostream>
using namespace std;

static int objectCount;
MyString::MyString()
{
	str = new char[80];
	size = 0;
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

	char* newStr = new char[newSize + 1];
	int newIndex = 0;
	for (int i = 0; i < size; ++i) {
		if (str[i] != c) {
			newStr[newIndex++] = str[i];
		}
	}
	newStr[newSize] = '\0';

	delete[] str;
	str = newStr;
	size = newSize;//Like (size -count of c)
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

MyString& MyString::operator++()
{
		MyString temp("X");
		MyStrCat(temp);
		return *this;
	
}



MyString& MyString::operator+=( MyString& b)
{
	MyStrCat(b); 
	return *this;
}

bool MyString::operator==(const MyString& obj)  
{
	return MyStrStr(obj.str);
}

bool MyString::operator!=(const MyString& obj) 
{
	return !MyStrStr(obj.str);
}



