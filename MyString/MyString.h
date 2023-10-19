#pragma once
class MyString
{
private:
	char* str;
	int size;
	

public:
	

	MyString(); //конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
	MyString(int); //конструктор, позволяющий создавать строку произвольного размера;
	MyString(char c);
	MyString(const char*);//конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя. 
	MyString(const MyString&);//Конструктор копирования
	~MyString();//Деструктор 
	MyString(initializer_list<char> param);// Иницалайзер-лист конструктор


	//методы для ввода строк с клавиатуры и вывода строк на экран.
	void Print();
	void Input();

	void MyStrcpy(MyString& obj);// копирование строк

    bool MyStrStr(const char* sub);// поиск подстроки в строке

	int  MyChr(char c);// поиск символа в строке(индекс найденного символа, либо -1)

	int MyStrLen();// возвращает длину строки

	void MyStrCat(MyString& b); // объединение строк

	void MyDelChr(char c); // удаляет указанный символ 


	int MyStrCmp(MyString& b); // сравнение строк(-1 – первая строка меньше чем вторая)(1 – первая больше чем вторая)(0 – строки равны!)


	void SetStr(const char* n);
	char* GetStr();

	void SetSize(int n);
	int GetSize();
	static int GetTotalObjects();



	//ПЕРЕГРУЗКИ ОПЕРАТОРОВ методом
	
	//MyString operator+(const MyString& b); //сложение для конкатенации,
    MyString& operator+=( MyString&b); //сложение для конкатенации,
	MyString operator+(MyString& b);// объединение строк перегрузка оператора +
	//MyString&  operator++();  //инкременты для увеличения длины строки


	//Перегрузка оператора индексирования 
	char& operator[](const int index);

	
	void operator() ();//Input.Перегрузка оператора преобразования типа.возвращает другой тип например matrix(1,2)=4.5(матрица возвращает дабл) 
	


	//MyString operator+(char c);
	//MyString operator+(int b);


	/*bool operator==(const MyString& obj);
	bool operator!=(const MyString& obj);*/

	MyString& operator=(const MyString& b);//Перегрузка оператора =

	MyString(MyString&& b); // Конструктор переноса
	MyString& operator=(MyString&& obj); //Перегрузка оператора присваивания с переносом.
	


