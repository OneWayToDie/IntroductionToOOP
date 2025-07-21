#include"Cringe.h"

void Clear(char* str)
{
	delete[] str;
}

//#define CONSTRUCTORS_CHECK
//#define copySemantic_check 

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(5);		//Conversion from 'int' to 'String'
	str2.print();

	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = "World";
	str4.print();
	cout << delimiter << endl;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;
	
	/*str5.print();*/
#endif
#ifdef copySemantic_check
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;
	String str2 = str1;
	cout << str2 << endl;
#endif

	//MoveMethods (MoveSemantic)
	String str1; //DefaultConstructor
	str1.print();

	String str2(5);	//Single-argument Constructor (int)
	str2.print();

	String str3 = "Hello ";	//Single-argument Constructor (const char str[])
	str3.print();

	String str4();	//В этой строке не вызывается DefaultConstructor, и НЕ создаётся объект
					//здесь объявляется функция 'str4', которая ничего не принимает и возвращает
					//значение типа 'string'.
	//str4 НЕ является объектом.
	//то есть, круглые скобки не делают явный вызов конструктора по умолчанию,
	//если есть необходимость явно вызвать конструктор по умолчанию, то это можно сделать
	//при помощи фигурных скобок
	String str5{};	//А эта строка уже явно вызывает DefaultConstructor()
	str5.print();

	String str6{ 6 };	//Single-argument Constructor (int)
	str6.print();

	String str7{ "World" };
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();

	String str10{ str9 };
	str10.print();

	//!!! Фигурные скобки для вызова конструкторов следует использовать с большой осторожностью!!!
	
	String str11 = str3 + str8;
	str11.print();
	cout << str11 << endl;
}