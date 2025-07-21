#include<iostream>
#include"Fraction.h"
#include"Point.h"
#include"Cringe.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	C = A / B;
	C.print();

	A *= B;
	A.print();

	A /= B;
	A.print();

	C = A + B;
	C.print();

	C = B - A;
	C.print();

	A += B;
	A.print();

	A -= B;
	A.print();

	cout << (Point(2, 3) != Point(7, 3)) << endl;

	String str1; //DefaultConstructor
	str1.print();

	String str2(5);	//Single-argument Constructor (int)
	str2.print();

	String str3 = "Hello ";	//Single-argument Constructor (const char str[])
	str3.print();

}