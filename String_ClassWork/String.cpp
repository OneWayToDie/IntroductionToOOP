#include"String.h"
///------------------------------------------------------------------///


///////////////////////////////////////////////////////////////////////
//////////		определение класса(class defenition)		//////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//			Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//Конструктор по умолчанию создаёт пустую строку, размером 80 байт
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;		//strlen() возвращает размер строки в символах, +1 нужен чтобы выделилась память под NULL-Terminator
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constuctor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->str = other.str;*/ //Shallow copy
	///-----------------------------------------------------------///
	//Deep copy:
	/*this->size = other.size;
	this->str = new char[size] {};*/
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//MoveConstructor - ShallowCopy:
	//this->size = other.size;
	//this->str = other.str;
	//обнуляем принимаемый объект для того чтобы предотвратить удаление его ресурсов деструктором
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	str = nullptr;
	size = 0;
	cout << "Destructor:\t\t" << this << endl;
}
//					Operators:
//type	  name	  (parameters)
String& String::operator=(const String& other)
{
	//this->str = other.str;		//Shallow copy - поверхностное копирование;
	///----------------------------------///
	//0) ПРОВЕРЯЕТСЯ, НЕ ЯВЛЯЕТСЯ ЛИ ТОТ ОБЪЕКТ ЭТИМ ОБЪЕКТОМ
	if (this == &other) return *this;
	//1) В первую очередь удаляем старую динамическую память
	delete[] this->str;
	//Deep Copy - побитовое копирование;
	this->size = other.size;
	//2) Выделяем новую динамическую память:
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	//0) Проверка не являются ли 'this' и 'other' одним и тем же объектом
	if (this == &other)return *this;
	//1) Удаление старой памяти
	delete[] str;
	//2) Shallow copy
	this->size = other.size;
	this->str = other.str;
	//3) Обнуляем принимаемый объект
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
char String::operator[](int i)const
{
	return str[i];	//Index operator, Subscript operator
}
char& String::operator[](int i)
{
	return str[i];
}
//				Methods
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
	/*result.get_str()[i] = left.get_str()[i];	*/
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
	/*result.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////		Конец определения класса(class defenition)	  //////////
///////////////////////////////////////////////////////////////////////
