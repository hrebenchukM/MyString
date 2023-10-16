#include<iostream>
#include "MyString.h"
#include <cassert> 
using namespace std;



istream& operator >>(istream& is, MyString& b)
{


	char* str = new char[100]; // максимальная длина вводимой строки 
	is >> str;
	b.SetStr(str);
	b.SetSize(strlen(str));
	delete[] str;
	return is;


}
ostream& operator <<(ostream& os, MyString& b)
{
	os << b.GetStr() << endl;
	os << b.GetSize() << endl;

	return os;

}


MyString operator++(MyString& b,int useless)//a++
{
	MyString result(b);
	MyString temp('X');
	result.MyStrCat(temp);
	return result;

}




MyString operator++(MyString& b)//++a
{
	MyString temp('X');
	temp.MyStrCat(b);
	return temp;
}





MyString operator+(MyString& str,int b)
{
	int size = str.GetSize();
	int newSize = size + b;
//	MyString rez(newSize + 1);


	char* arr0 = new char[b + 1];
	for (int i = 0; i < b; i++)
	{
		arr0[i] = '0';
	}
	arr0[b] = '\0';

	MyString newstr(arr0);
	MyString newstr2(str);
	newstr2.MyStrCat(newstr);
	return newstr2;
}


MyString operator+(int b,MyString& str )
{
	int size = str.GetSize();
	int newSize = size + b;
//	MyString rez(newSize + 1);


	char *arr0= new char[b+1];
	for (int i = 0; i < b; i++)
	{
		arr0[i] = '0';
	}
	arr0[b] = '\0';

	MyString newstr(arr0);
	newstr.MyStrCat(str);
	return  newstr;


}




MyString operator+(MyString& b,char c)
{
	MyString newstr(b);
	MyString s2(c);
	newstr.MyStrCat(s2);
	return newstr;
}

MyString operator+(char c, MyString& b)
{
	MyString s2(c);
	s2.MyStrCat(b);
	return s2;
}

int main()
{
	MyString s4 = MyString("Test");
	MyString s5 = MyString("Test");
	MyString s8 = MyString("Test=");

	MyString s6= MyString("Test by Mary Hrebenchuk");

	MyString s = MyString("This is test");
	s.Print();
	cout << endl;

	MyString s2 = MyString(".Very tasty...");
	s2.Print();
	cout << endl;

    // копирование строк
	MyString s3;// = s;
	s3.MyStrcpy(s);
	s3.Print();
	cout <<endl;

	// поиск подстроки в строке
	//Протестировать два случая одним запуском программы
	assert(s.MyStrStr("test"));//Резултат должен быть true
	assert(!s.MyStrStr("test2"));//!Резултат должен быть false


	// поиск символа в строке(индекс найденного символа, либо -1)
	assert(8 == s.MyChr('t'));//Резултат должен быть true
	assert(-1 == s.MyChr('b'));//!Резултат должен быть false

	// возвращает длину строки
	assert(12 == s.MyStrLen());



	// объединение строк с использованием перегрузки оператора +
	MyString result = s + s2;
	assert(strcmp(result.GetStr(), "This is test.Very tasty...") == 0); // Проверяем, что строки объединены верно

	// удаление символа 'e' из строки
	s.MyDelChr('i');
	assert(strcmp(s.GetStr(), "Ths s test") == 0);// Проверяем, что символ 'e' удален верно

	// сравнение строк
	
	assert(s5.MyStrCmp(s4) == 0); // Ожидается 0, так как строки равны
	assert(s5.MyStrCmp(s6) < 0); // Ожидается -1, так как первая строка меньше второй
	assert(s6.MyStrCmp(s4) > 0); // Ожидается 1, так как первая строка больше второй


	////Перегрузка оператора индексирования
	assert('T' == s4[0]);
	assert('e' == s4[1]);
	assert('s' == s4[2]);
	assert('t' == s4[3]);
	assert('t' == s4[100]);


	//Перегрузка оператора преобразования типа Input
	/*MyString s10;
	s10();
	s10.Print();*/

	MyString s11 = s4 + '!';
	assert(strcmp(s11.GetStr(), "Test!") == 0);
	//s11.Print();

	MyString s12 = '!' + s4;
//	s12.Print();
	assert(strcmp(s12.GetStr(), "!Test") == 0);









	MyString s13 = s4 + 10;
	//s13.Print();
	assert(strcmp(s13.GetStr(), "Test0000000000") == 0);

	MyString s14 =  10 + s4;
	//s14.Print();
	assert(strcmp(s14.GetStr(), "0000000000Test") == 0);



	MyString s15 = ++s4;
	//s15.Print();
	assert(strcmp(s15.GetStr(), "XTest") == 0);

	MyString s16 = s8++;
	//s16.Print();
	assert(strcmp(s16.GetStr(), "Test=X") == 0);


	s8 = s6;
	assert(strcmp(s8.GetStr(), "Test by Mary Hrebenchuk") == 0);


	

	MyString str1;
	cout << "Enter a string: ";
	cin >> str1; 
	cout << "Your string: ";
	cout << str1 << endl;

	cout << endl << "All tests passed!" << endl;

}