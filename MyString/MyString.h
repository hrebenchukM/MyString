#pragma once
class MyString
{
private:
	char* str;
	int size;
	

public:
	

	MyString(); //����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
	MyString(int); //�����������, ����������� ��������� ������ ������������� �������;
	MyString(char c);
	MyString(const char*);//�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������. 
	MyString(const MyString&);//����������� �����������
	~MyString();//���������� 


	//������ ��� ����� ����� � ���������� � ������ ����� �� �����.
	void Print();
	void Input();

	void MyStrcpy(MyString& obj);// ����������� �����

    bool MyStrStr(const char* sub);// ����� ��������� � ������

	int  MyChr(char c);// ����� ������� � ������(������ ���������� �������, ���� -1)

	int MyStrLen();// ���������� ����� ������

	void MyStrCat(MyString& b); // ����������� �����

	void MyDelChr(char c); // ������� ��������� ������ 


	int MyStrCmp(MyString& b); // ��������� �����(-1 � ������ ������ ������ ��� ������)(1 � ������ ������ ��� ������)(0 � ������ �����!)


	char* GetStr();
	int GetSize();
	static int GetTotalObjects();



	//���������� ���������� �������
	// 
	//MyString operator+(const MyString& b); //�������� ��� ������������,
    MyString& operator+=( MyString&b); //�������� ��� ������������,
	MyString operator+(MyString& b);// ����������� ����� ���������� ��������� +
	//MyString&  operator++();  //���������� ��� ���������� ����� ������
	//  
	//���������� ��������� �������������� 
	char& operator[](const int index);
	//���������� ��������� �������������� ����
	//���������� ������ ��� �������� matrix(1,2)=4.5// ������� ���������� ���� 
	void operator() (); //Input
	//MyString operator+(char c);
	//MyString operator+(int b);


	/*bool operator==(const MyString& obj);
	bool operator!=(const MyString& obj);*/

};

