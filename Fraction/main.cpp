#include<iostream>
using namespace std;


class Fraction
{
	int integer; //Целая часть
	int numerator; //Числитель
	int denominator; //Знаменатель
	//int divisible;	//Делимое
	//int divider; //делитель

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//		Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		//numerator++;
		//denominator++;
		return old;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	Fraction operator+(int)
	{

	}

	//		Methods:
	Fraction& to_improper()
	{
		//перевод в неправильную дробь:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		//перевод в правильную дробь:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator*( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	//Fraction result
	//(
	//	left.get_numerator()*right.get_numerator(),
	//	left.get_denominator()*right.get_denominator()
	//);
	//result.to_proper();
	//return result;
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();
}


bool operator==(const Fraction& left, const Fraction& right)
{
	return left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator() && left.get_integer() == right.get_integer();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	return left.get_numerator() > right.get_numerator();
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return left.get_numerator() < right.get_numerator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return left.get_numerator() >= right.get_numerator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left.get_numerator() <= right.get_numerator();
}

//#define CONSTRUCTORS_CHECK 
//#define MULTIPLICATION_CHECK
//#define DIVISION_CHECK
//#define COMPARISON
//#define  INCREMENT_CHECK
#define PLUS_MINUS
//#define COMPOUND_ASSIGNMENTS
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Defauls constructor
	A.print();

	Fraction B = 5; //Single-Argument constructor
	B.print();

	Fraction C(1,2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif //CONSTRUCTORS_CHECK
#ifdef MULTIPLICATION_CHECK
	Fraction A(1, 2, 3);
	A.print();

	Fraction B(2, 3, 4);
	B.print();

	Fraction C = A * B;
	C.print();
#endif //MULTIPLICATION_CHECK
#ifdef DIVISION_CHECK
	Fraction A(1, 2, 3);
	A.print();

	Fraction B(2, 3, 4);
	B.print();

	Fraction C = A / B;
	C.print();
#endif //DIVISION_CHECK
#ifdef COMPARISON
	cout << (Fraction(1, 2, 3) == Fraction(2, 3, 4)) << endl;
	cout << (Fraction(1, 2, 3) != Fraction(2, 3, 4)) << endl;
	cout << (Fraction(1, 2, 3) > Fraction(2, 3, 4)) << endl;
	cout << (Fraction(1, 2, 3) < Fraction(2, 3, 4)) << endl;
	cout << (Fraction(1, 2, 3) >= Fraction(2, 3, 4)) << endl;
	cout << (Fraction(1, 2, 3) <= Fraction(2, 3, 4)) << endl;
#endif
#ifdef INCREMENT_CHECK
	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);
	A = B++;
	A.print();
	B.print();
	A = B--;
	A.print();
	B.print();
#endif
#ifdef PLUS_MINUS
	Fraction A(1, 2, 3);
	A.print();

	Fraction B(2, 3, 4);
	B.print();

	Fraction C = A + B;
	C.print();

	Fraction D = B - A;
	D.print();
#endif
#ifdef COMPOUND_ASSIGNMENTS

#endif
}