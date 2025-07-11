#include<iostream>
using namespace std;

class Fraction; //объявление класса
Fraction operator*(Fraction left, Fraction right); //объявление оператора
Fraction operator/(const Fraction& left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, const Fraction& obj);

class Fraction	// Описание класса
{
	int integer; //Целая часть
	int numerator; //Числитель
	int denominator; //Знаменатель
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
	explicit Fraction(int integer)
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
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	//Incremento/Decremento:
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	//					Type-cast operators:

	explicit operator int()const
	{
		/*to_improper();*/ //evaluate as a constant
		return integer + numerator/denominator;
	}
	//operator double()const
	//{
	//	return double(numerator) / denominator;
	//}
	explicit operator double()const
	{
		return (double)numerator/denominator;
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
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); // функция swap() меняет местами две переменные
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		//more - больше
		//less - меньше
		//rest - остаток
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while(rest);
		int GCD = more; // GCD - greatest common divisor(наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
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

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
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
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, Fraction right)
{
	return left * right.inverted();
}
//			Comparison operator:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	/*return left > right || left == right;*/
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	/*return left < right || left == right;*/
	return !(left > right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}


std::istream& operator>>(std::istream& is, const Fraction& obj)
{
	if (obj.get_integer() >> obj.get_integer())is;
	if (obj.get_numerator())
	{
		obj.get_numerator() / obj.get_denominator();
	}
	else if (obj.get_integer() == 0 >> 0)is;
	return is;
}


//#define CONSTRUCTORS_CHECK //ctrl+shift+u = верхний/нижний регистр
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CHECK
//#define COMPARISON
//#define LOGICAL_OPERATORS
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
#define HAVE_A_NICE_TWO_DAY_AND_TWO_NIGHT_I_GO_INTO_HELL
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Defauls constructor
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
	Fraction A = Fraction(2.75);
	cout << A << endl;
#endif
}