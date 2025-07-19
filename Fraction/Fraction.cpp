#include"Fraction.h"
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//		Constructors:
Fraction::Fraction() :integer(0), numerator(0), denominator(0)
{
	//this->integer = 0;
	//this->numerator = 0;
	//this->denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal) :integer(decimal), denominator(1e+9)/*, numerator(decimal*denominator)*/
{
	//decimal десятичное число
	decimal += 1e-10;
	//integer = decimal;			//1)получаем целую часть дроби
	decimal -= integer;			//2)убираем целую часть из десятичной дроби
	//denominator = 1e+9;			//3) получаем масимально возможный знаменатель - 1000000000;
	numerator = decimal * denominator;//4)Вытаскиваем дробную часть в числитель;
	reduce();
	cout << "SingleArgumentConstructor:" << this << endl;
}
Fraction::Fraction(int integer) :integer(integer), numerator(0), denominator(1)
{
	//this->integer = integer;
	//this->numerator = 0;
	//this->denominator = 1;
	cout << "SingleArgumentConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) :integer(0), numerator(numerator)
{
	/*this->integer = 0;
	this->numerator = numerator;*/
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator) :integer(integer), numerator(numerator)
{
	//this->integer = integer;
	//this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) :integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	//this->integer = other.integer;
	//this->numerator = other.numerator;
	//this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}
//		Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}
//Incremento/Decremento:
Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}
//					Type-cast operators:
Fraction::operator int()const
{
	/*to_improper();*/ //evaluate as a constant
	return integer + numerator / denominator;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}
//		Methods:
Fraction& Fraction::to_improper()
{
	//перевод в неправильную дробь:
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	//перевод в правильную дробь:
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator); // функция swap() меняет местами две переменные
	return inverted;
}
Fraction& Fraction::reduce()
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
	} while (rest);
	int GCD = more; // GCD - greatest common divisor(наибольший общий делитель)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
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