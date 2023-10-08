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
	void MyStrcpy(MyString& obj);// ����������� �����
    bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c);// ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyStrCat(MyString& b); // ����������� �����
	MyString operator+(MyString& b);
	char* GetStr();
	int GetSize();

};

