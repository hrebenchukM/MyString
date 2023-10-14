#pragma once
class MyString
{
private:
	char* str;
	int size;
	

public:
	

	MyString(); //конструктор по умолчанию, позвол€ющий создать строку длиной 80 символов;
	MyString(int); //конструктор, позвол€ющий создавать строку произвольного размера;
	MyString(char c);
	MyString(const char*);//конструктор, который создаЄт строку и инициализирует еЄ строкой, полученной от пользовател€. 
	MyString(const MyString&);// онструктор копировани€
	~MyString();//ƒеструктор 


	//методы дл€ ввода строк с клавиатуры и вывода строк на экран.
	void Print();
	void Input();

	void MyStrcpy(MyString& obj);// копирование строк

    bool MyStrStr(const char* sub);// поиск подстроки в строке

	int  MyChr(char c);// поиск символа в строке(индекс найденного символа, либо -1)

	int MyStrLen();// возвращает длину строки

	void MyStrCat(MyString& b); // объединение строк

	void MyDelChr(char c); // удал€ет указанный символ 


	int MyStrCmp(MyString& b); // сравнение строк(-1 Ц перва€ строка меньше чем втора€)(1 Ц перва€ больше чем втора€)(0 Ц строки равны!)


	char* GetStr();
	int GetSize();
	static int GetTotalObjects();



	//ѕ≈–≈√–”« » ќѕ≈–ј“ќ–ќ¬ методом
	// 
	//MyString operator+(const MyString& b); //сложение дл€ конкатенации,
    MyString& operator+=( MyString&b); //сложение дл€ конкатенации,
	MyString operator+(MyString& b);// объединение строк перегрузка оператора +
	//MyString&  operator++();  //инкременты дл€ увеличени€ длины строки
	//  
	//ѕерегрузка оператора индексировани€ 
	char& operator[](const int index);
	//ѕерегрузка оператора преобразовани€ типа
	//возвращает другой тип например matrix(1,2)=4.5// матрица возвращает дабл 
	void operator() (); //Input
	//MyString operator+(char c);
	//MyString operator+(int b);


	/*bool operator==(const MyString& obj);
	bool operator!=(const MyString& obj);*/

};

