#pragma once
#include<iostream>
using namespace std;

#define delimiter	"\n---------------------------------------\n"

///////////////////////////////////////////////////////////////////////
//////////		объ€вление класса(class declaration)		//////////
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;	//размер строки в Ѕайтах (с учЄтом NULL-Terminator)
	char* str;	//адрес строки в динамической пам€ти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//			Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//					Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);
	//				Methods
	void print()const;
};
//////////	конец объ€влени€ класса(class declaration)		  //////////
///////////////////////////////////////////////////////////////////////

