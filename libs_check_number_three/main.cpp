#include<iostream>
#include"Fraction.h"
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
}