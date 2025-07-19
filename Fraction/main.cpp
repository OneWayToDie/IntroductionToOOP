#include"Fraction.h"

//#define CONSTRUCTORS_CHECK //ctrl+shift+u = верхний/нижний регистр
#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CHECK
//#define COMPARISON
//#define LOGICAL_OPERATORS
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_TWO_DAY_AND_TWO_NIGHT_I_GO_INTO_HELL
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Defaults constructor
	A.print();

	Fraction B = 5; //Single-Argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif //CONSTRUCTORS_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
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

#endif
#ifdef INCREMENTO_DECREMENTO_CHECK
	double a = 2;
	double b = 0;
	b += a++;
	cout << a << endl;
	cout << b << endl;
	Fraction A(2, 3, 4);
	Fraction B;
	B += A++;
	A.print();
	B.print();
#endif
#ifdef COMPARISON
	cout << (Fraction(1, 2) == Fraction(5, 11)) << endl;
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;
	cout << (Fraction(1, 2) > Fraction(5, 11)) << endl;
	cout << (Fraction(1, 3) < Fraction(5, 11)) << endl;
	cout << (Fraction(1, 2) >= Fraction(5, 11)) << endl;
	cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
#endif
#ifdef LOGICAL_OPERATORS
	/*for (Fraction i(9, 1, 2); i > 0; --i)
	{
		i.print();
	}*/

	Fraction A(2, 3, 4);
	cout << A << endl;
#endif
#ifdef STREAMS_CHECK
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif
#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2; // No conversion
	double b = 3; //Conversion from less to more
	int c = b; //Conversion from more to less without data loss
	int d = 5.5; //Conversion from more to less with data loss
#endif
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;		//Single-Argument Constructor(From less to more)
	cout << A << endl;
	//cout << sizeof(Fraction) << endl;
	Fraction B;
	B = Fraction(8);//singleArgumentConstructor -> CopyAssignment(From less to more)
	//Single-Argument Constructor создаёт из 8 временный безымянный объект
	//а оператор присваивания просто записывает его в существующий объект 'B'
#endif
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	/*
	-----------------------------------------------
	operator type()
	{

	}
	-----------------------------------------------
	*/
	Fraction A(2, 3, 4);
	A.to_improper().print();
	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;
#endif
#ifdef HAVE_A_NICE_TWO_DAY_AND_TWO_NIGHT_I_GO_INTO_HELL
	Fraction A = 3.33;		//Conversion from 'double'
	cout << A << endl;
#endif
}