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

    // копирование строк
	MyString s3;// = s;
	s3.MyStrcpy(s);
	s3.Print();

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
	s.MyDelChr('e');
	assert(strcmp(s.GetStr(), "This is tst.Vry tasty...") == 0);// Проверяем, что символ 'e' удален верно

	// сравнение строк
	MyString s4 = MyString("This is test");
	assert(s.MyStrCmp(s4) == 0); // Ожидается 0, так как строки равны
	assert(s.MyStrCmp(s2) < 0); // Ожидается -1, так как первая строка меньше второй
	assert(s2.MyStrCmp(s4) > 0); // Ожидается 1, так как первая строка больше второй



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