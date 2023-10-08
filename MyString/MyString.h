#pragma once
class MyString
{
private:

	char* str;
	int size;

public:
	MyString();
	MyString(int);
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
	void Print();
	void Input();
	void MyStrcpy(MyString& obj);// копирование строк
    bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c);// поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyStrCat(MyString& b); // объединение строк
	MyString operator+(MyString& b);
	char* GetStr();
	int GetSize();

};

