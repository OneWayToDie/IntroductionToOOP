#include<iostream>
#include"String.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	String str1; //DefaultConstructor
	str1.print();

	String str2(5);	//Single-argument Constructor (int)
	str2.print();

	String str3 = "Hello ";	//Single-argument Constructor (const char str[])
	str3.print();
}