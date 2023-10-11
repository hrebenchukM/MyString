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
	s.MyDelChr('i');
	assert(strcmp(s.GetStr(), "Ths s test") == 0);// Проверяем, что символ 'e' удален верно

	// сравнение строк
	
	assert(s5.MyStrCmp(s4) == 0); // Ожидается 0, так как строки равны
	assert(s5.MyStrCmp(s6) < 0); // Ожидается -1, так как первая строка меньше второй
	assert(s6.MyStrCmp(s4) > 0); // Ожидается 1, так как первая строка больше второй



	cout << endl<<"All tests passed!" << endl;





}